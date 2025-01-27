#include <stdio.h>  // stdio.h gives us printf
#include <string.h> // string.h gives us strlen
#include <ctype.h>

/*
   This program determines the count of each specific ASCII
   character in a given literal string, then reports the
   two most frequently-occurring.
*/


int main() {
    const char text[] = "4 score and 7 years ago our fathers brought "
                       "4th on this continent, a new nation, "
                       "conceived in Liberty, and dedic8d to the "
                       "proposition that all men are cre8d =";

    int ascii_count[256] = {0};
    int text_len = strlen(text);

    // TODO A: with a single loop, count the # occurrences of
    //         each ascii character
    // HINT: use each char of the text as an offset into the
    //       ascii_count array, then update using increment (++)







    // determine the two most frequently occurring chars
    char top_char = '\0';
    int top_freq = 0;

    char next_char = '\0';
    int next_freq = 0;

    // TODO B: With a single loop find the most frequent and
    //         second-most-frequent characters in the text.
    //         Store most frequent character and its frequency
    //         in top_char and top_freq.
    //         Store second-most-frequent character and its
    //         frequency in next_char and next_freq.









    // output results
    printf("'%c' occurred %d times, '%c' occurred %d times\n",
	   top_char, top_freq, next_char, next_freq);
}
