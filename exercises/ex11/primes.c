#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// This program has a bug.  valgrind can help you find it.
//
// Hint 1: the bug is not in the is_prime function
// Hint 2: if at first valgrind says there's no bug, try
//         increasing MAX_CANDIDATE and try again

// Compile with:
//    gcc -std=c99 -pedantic -Wall -Wextra primes.c -lm -o primes -g
// Run with:
//    valgrind --leak-check=full ./primes


#define MAX_CANDIDATE 50000

// return non-zero if argument is prime, otherwise return 0
int is_prime(int number) {
    if (number < 2) {
        return 0;
    }
    for (int i = 2; i <= (int)sqrt(number); i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int set_primes( int *list , int capacity )
{
    int idx = 0; // index of the next prime to add
    for( int n=2 ; n<MAX_CANDIDATE ; n++ )
    {
        if( is_prime(n) )
        {
            // have we filled the list to capacity?
            if( idx==capacity )
            {
                // double the # ints "list" can hold
                capacity *= 2;
                list = realloc(list, capacity * sizeof(int));
            }
            list[idx++] = n;
        }
    }
    return idx;
}

// accumulate a list of primes
int main() {
    // # of primes "list" can hold
    int capacity = 10;
    // list for holding primes we find
    int *list = malloc(capacity * sizeof(int));
    if (list == NULL) {
        printf("Could not allocate list\n");
        return 1;
    }
    int prime_count = set_primes( list , capacity );
    printf( "Found %d primes in the range [2,%d)\n" , prime_count , MAX_CANDIDATE );
    printf( "First and last primes are %d and %d\n" , list[0] , list[ prime_count-1 ] );
    free(list);
    return 0;
}
