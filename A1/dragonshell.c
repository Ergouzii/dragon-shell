#include <stddef.h>
#include <string.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

const char *WELCOME = "...........................................\n\
........=..................................\n\
.........=#-.......-:*==+..................\n\
...........=W=-..........+W#-..............\n\
.............-=WW=:.......:WWW:............\n\
.................:#WWWW@@WWWWWW@-..........\n\
...............+#WWWWWWWWWW@--=WW@-........\n\
....*@#=#WWWWWWWWWWWWWWWWWWWWWW@WW*........\n\
........:@WWWWWWWWWWWWWWWWWWWWWWWWWW@*-....\n\
......-@WWWWWWWWWWWWWWWWWW*@WWWWWWWWWWW=#+.\n\
..-=WWWWWWWWWWWWWW@+.:WW=:W+.*:.#@:#W#@WWW@\n\
-#-.+WWWWWWWWWWWW+....:WW*.:@:...+..-*.+#*W\n\
-...@WWWWWWWWWWW*......*WW@+.:@-..........+\n\
...-WWWWWWWWWWWW:.......+WW=...-=#:........\n\
..:WWWWWWWWWWWWW@.........:@W*--...-:*=::..\n\
.:#.=WWWWWWWWWWWWW:..........-++:..........\n\
.+..-WWWWWWWWWWWWWWW@+.....................\n\
.....#WWWWWWWWWWWWWWWWWW#:.................\n\
....#=-@WWWWWWWWWWWWWWWWWWW@:..............\n\
...-*...#WWWWWWWWWWWWWWWWWWWWW:............\n\
...--....*WWWWWWWWWWWWWWWWWWWWW*...........\n\
..........*WWWWWWWWWWWWWWWWWWWWW-..........\n\n\
********Welcome to the Dragonshell*********\n";

char PATH[100] = "/bin/:/usr/bin/";

// TODO: these are for debugging uses
const char *OK = "**OK**";
const char *BAD = "**BAD**";

void tokenize(char *str, const char *delim, char **argv);
int handle_input();
int handle_cd(char *tokenized[]);
int handle_pwd(char *tokenized[]);
int handle_path(char *tokenized[]);
int handle_a2path(char *tokenized[]);
int handle_exit(char *tokenized[]);

int main(int argc, char **argv) {
  // print the string prompt without a newline, before beginning to read
  // tokenize the input, run the command(s), and print the result
  // do this in a loop

  printf("%s", WELCOME); // prints welcome text

  while (1) {
    handle_input();
  }

  return 0;
}

/**
 * @brief Tokenize a C string 
 * 
 * @param str - The C string to tokenize 
 * @param delim - The C string containing delimiter character(s) 
 * @param argv - A char* array that will contain the tokenized strings
 * Make sure that you allocate enough space for the array.
 */
void tokenize(char *str, const char *delim, char **argv) {
  char *token;
  token = strtok(str, delim); // getting first token
  for(size_t i = 0; token != NULL; ++i){ //getting the following tokens
    argv[i] = token;
    token = strtok(NULL, delim);
  }
}

int handle_input() {
  printf("\ndragonshell>> ");

  // get input
  char input[100];
  if (fgets(input, sizeof(input), stdin) == NULL) { 
    // catching ctrl + D, exit shell as catched
    char *exiting = "\ndragonshell: Exiting\n";
    printf("%s\n", exiting);
    _exit(1);
  }; 

  // remove newline at the end of "fgets"
  size_t len = strlen(input) - 1;
  if (input[len] == '\n') {
    input[len] = '\0';
  }

  size_t empty = 0;
  if (strlen(input) == empty) { // if input is empty
    char *empty_input = "dragonshell: please give an input\n";
    printf("%s", empty_input);  
  } else if (input[0] == ' ') { // if space at start of line
    char *space_start = "dragonshell: please do not include space at start of line\n";
    printf("%s", space_start);  
  } else { // if input is not empty
    // tokenize the input
    char *delim = " ";
    char **tokenized = malloc(sizeof(char) * 100);
    tokenize(input, delim, tokenized);

    // check which cmd is entered and handle them
    char *cd_cmd = "cd";
    char *pwd_cmd = "pwd";
    char *path_cmd = "$PATH";
    char *a2path_cmd = "a2path";
    char *exit_cmd = "exit";
    char *input_cmd = tokenized[0];
    if (strcmp(input_cmd, cd_cmd) == 0) { // if cd cmd
      handle_cd(tokenized);
    } else if (strcmp(input_cmd, pwd_cmd) == 0) { // if pwd cmd
      handle_pwd(tokenized);
    } else if (strcmp(input_cmd, exit_cmd) == 0) {
      handle_exit(tokenized);
    } else if (strcmp(input_cmd, path_cmd) == 0) {
      handle_path(tokenized);
    } else if (strcmp(input_cmd, a2path_cmd) == 0) {
      handle_a2path(tokenized);
    } else {
      char *unknown = "dragonshell: Command not found\n";
      printf("%s", unknown);
    }
  }

  return 0;
}

int handle_cd(char *tokenized[]) {
  char *arg = tokenized[1];
  if (arg == NULL) { // if no argument given
    char *no_argument = "dragonshell: expected argument to \"cd\"\n";
    printf("%s", no_argument);
    return 1;
  } else if (tokenized[2] != NULL) { // if 3rd argument is given
    char *three_arguments = "dragonshell: too many arguments for \"cd\"\n";
    printf("%s", three_arguments);
    return 1;
  } else { // if 2nd argument is given
    if (strcmp(arg, "..") == 0) {
      chdir("..");
    } else { // cd to some dir
      if (chdir(arg) == 0) {
        chdir(arg);
      } else {
        char *wrong_dir = "dragonshell: No such file or directory\n";
        printf("%s", wrong_dir);
        return 1;
      }
    }
  }
  return 0;
}

int handle_pwd(char *tokenized[]) {
  char cwd[100];
  printf("%s\n", getcwd(cwd, 100)); 
  return 0;
}

int handle_path(char *tokenized[]) {
  printf("Current PATH: %s\n", PATH);
  return 0;
}

int handle_a2path(char *tokenized[]) {
  char *arg = tokenized[1];
  if (arg == NULL) { // if no argument given
    char *no_argument = "dragonshell: expected argument to \"a2path\"\n";
    printf("%s", no_argument);
    return 1;
  } else if (tokenized[2] != NULL) { // if 3rd argument is given
    char *three_arguments = "dragonshell: too many arguments for \"a2path\"\n";
    printf("%s", three_arguments);
    return 1;
  } else { // if only 1 arg given (normal use case)
    if (strncmp(arg, "$PATH:", 6) != 0) { // if arg does not start with "$PATH"
      char *no_append_path = "dragonshell: please enter in form of \"a2path $PATH:/*/*/*\"\n";
      printf("%s", no_append_path);
      return 1;
    } else { // if arg gives something to add
      char **tokenized_arg = malloc(sizeof(char) * 100);
      char *delim = ":";
      tokenize(arg, delim, tokenized_arg); // split the paths by ":"
      if (strcmp(tokenized_arg[0], "$PATH") != 0) { // if not adding path to $PATH
        char *wrong_append = "dragonshell: please add path to $PATH\n";
        printf("%s", wrong_append);
        return 1;
      } else { // if adding to $PATH
        strcat(PATH, ":");
        strcat(PATH, tokenized_arg[1]);
      }
      free(tokenized_arg);
    }
  }
  return 0;
}

int handle_exit(char *tokenized[]) {
  char *exiting = "dragonshell: Exiting\n";
  printf("%s\n", exiting);
  _exit(1);
  return 0;
}
