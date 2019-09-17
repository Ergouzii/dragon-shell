#include <stddef.h>
#include <string.h>

#include <readline/readline.h> 

#include <stdio.h>

/**
 * @brief Tokenize a C string 
 * 
 * @param str - The C string to tokenize 
 * @param delim - The C string containing delimiter character(s) 
 * @param argv - A char* array that will contain the tokenized strings
 * Make sure that you allocate enough space for the array.
 */
void tokenize(char* str, const char* delim, char ** argv) {
  char* token;
  token = strtok(str, delim); // getting first token
  for(size_t i = 0; token != NULL; ++i){ //getting the following tokens
    argv[i] = token;
    token = strtok(NULL, delim);
  }
}

void welcome(void) {
  printf("**********************************************");
  printf("**********Welcome to the Dragonshell**********");
  printf("**********************************************");
}

void cmdLoop(void) {
  int running;
  do {
    readInput();
  } while(running);
}

int readInput() {
  char* input;

  input = readline("\ndragonshell>> "); // get input

  if (strlen(input) != 0) { // if input is not empty
    return 0;
  } else {
    return 1;
  }
}

int main(int argc, char **argv) {
  // print the string prompt without a newline, before beginning to read
  // tokenize the input, run the command(s), and print the result
  // do this in a loop

  welcome();

  cmdLoop();

  return 0;
}
