#include <stdio.h>  // stdio.h gives us printf
#include <string.h> // string.h gives us strlen

#include <ctype.h>  // ctype.h gives us isalpha, isdigit, isspace
// See also: http://www.cplusplus.com/reference/cctype/


/* 
   This program determines and reports the number of alphabetic, 
   digit, and whitespace characters in a given string literal.
*/
int main() {
    const char text[] = "4 score and 7 years ago our fathers brought "
                       "4th on this continent, a new nation, "
                       "conceived in Liberty, and dedic8d to the "
                       "proposition that all men are cre8d =";

    int num_alpha = 0;  // # alphabet chars ('A'-'Z' and 'a'-'z')
    int num_digits = 0; // # digit chars ('0' - '9')
    int num_space = 0;  // # whitespace chars (spaces, tabs, newlines, etc)

    int text_len = strlen(text);

    // TODO: count alphabetical, digit and whitespace characters.
    // Optional challenge: instead of using isalpha, isdigit and
    // isspace, use relational operators and your knowledge of the
    // characters' ASCII values: http://www.asciitable.com


    





    // output results
    printf("# alphabetical:%d, # digit:%d, # whitespace:%d\n",
           num_alpha, num_digits, num_space);

    return 0;
}
