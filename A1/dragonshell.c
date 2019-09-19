#include <stddef.h>
#include <string.h>

#include <unistd.h>
#include <stdio.h>

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

void tokenize(char *str, const char *delim, char **argv);
char *get_input();

int main(int argc, char **argv) {
  // print the string prompt without a newline, before beginning to read
  // tokenize the input, run the command(s), and print the result
  // do this in a loop

  printf("%s", WELCOME); // prints welcome text

  while (1) {
    char *input = get_input();

    // convert char* to char[], so tokenize can run properly
    char input_arr[strlen(input)]; 
    for(size_t i = 0; i < strlen(input); i++){
      input_arr[i] = input[i];
    }

    char *delim = " ";
    char *tokenized[100];
    tokenize(input_arr, delim, tokenized);
    printf("\n%s", tokenized[1]);
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

char *get_input(void) {
  // TODO: can we use malloc? if not, cannot dynamicly change array size
  char input[100];
  char *input_ptr = input;

  printf("\ndragonshell>> ");
  fgets(input, sizeof(input), stdin); // get input

  return input_ptr;
}
