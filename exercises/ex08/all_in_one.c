#include <stdio.h>
#include <string.h>


/*
    Returns in the third argument the concatenation of the first
    argument and the second argument, provided that there is
    sufficient space in third argument, as specified by the fourth.
    The function should return 0 if successful and 1 otherwise.
    e.g.
        concat("alpha", "beta", result, 10) puts "alphabeta" into result and returns 0
        concat("alpha", "gamma", result, 10) puts nothing into result and returns 1
*/
int concat(const char word1[], const char word2[], char result[], int result_capacity){

   //TODO: replace the following stub with a correct function body so that 
   //      this function behaves as indicated in the comment above
   //
   //NOTE: you may not use the strcat or strcpy library functions in your solution!
   return -1;

}



int main() {

  char word1[11];  // allow up to 10 chars, then room for '\0' terminator
  char word2[11];  // allow up to 10 chars, then room for '\0' terminator
  char result[18]; // allow up to 17 chars, then room for '\0' terminator
  int result_size = (int)sizeof(result)/sizeof(char); // number of elements in the result array

  //collect two strings
  printf("Enter the first word (up to 10 characters): ");
  scanf("%s", word1);
  printf("Enter the second word (up to 10 characters): ");
  scanf("%s", word2);

  //Call the concat function output the results
  int return_val = concat(word1, word2, result, result_size);
  printf("Called concat(\"%s\",\"%s\", result, %d)\n", word1, word2, result_size);
  printf("Return value was %d and result now equals \"%s\", with length %lu\n\n", 
     return_val, result, strlen(result));

  return 0;

}

  /* Note: What happens if the user enters more than 10 characters
           when prompted for word1 or word2?  After you finish the
           rest of this exercise, try it out.

  */

