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

// TODO: these are for debugging uses
const char *OK = "**OK**";
const char *BAD = "**BAD**";

void tokenize(char *str, const char *delim, char **argv);
int handle_input();
int handle_cd();
int handle_pwd();

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
  char *input = malloc(sizeof(char) * 100);
  fgets(input, sizeof(input), stdin); // get input

  // remove newline at the end of "fgets"
  size_t len = strlen(input) - 1;
  if (input[len] == '\n') {
    input[len] = '\0';
  }

  // if input is empty
  size_t empty = 0;
  if (strlen(input) == empty) { 
    char *empty_input = "dragonshell: please give an input\n";
    printf("%s", empty_input);
    
  } else { // if input is not empty

    // tokenize the input
    char *delim = " ";
    char **tokenized = malloc(sizeof(char) * 100);
    tokenize(input, delim, tokenized);

    printf("%s\n", tokenized[0]);
    printf("%s", tokenized[1]);

    // check which cmd is entered and handle them
    char *cd_cmd = "cd";
    char *pwd_cmd = "pwd";
    char *input_cmd = tokenized[0];
    if (strcmp(input_cmd, cd_cmd) == 0) { // if cd cmd
      if (tokenized[1] == NULL) { 
        char *no_argument = "dragonshell: expected argument to \"cd\"";
        printf("%s", no_argument);
      }
    } else if (strcmp(input_cmd, pwd_cmd) == 0) { // if pwd cmd
      handle_pwd(tokenized);
    }
  }

  return 0;
}

int handle_cd() {
  return 0;
}

int handle_pwd() {
  return 0;
}