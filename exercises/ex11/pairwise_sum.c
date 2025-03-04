#include <stdio.h>
#include <stdlib.h>

// This program has a bug and a memory leak.
// valgrind can help you find them.

// Compile with:
//    gcc -std=c99 -pedantic -Wall -Wextra pairwise_sum.c -o pairwiseSum -g
// to run:
//    valgrind --leak-check=full ./pairwiseSum

// Let the "pairwise sum" of an array be another array
// where each element of the new array equals the sum of
// two consecutive elements of the original array

// The pairwise sum of array {1, 2, 3} is {3, 5}
// The pairwise sum of {3, 5} is {8}


// Find the pairwise sum of the array "array" of length
// "length" and return the result as a newly-allocated
// array.  Return NULL upon error.
int *pairwise_sum(int *array, int length) {
    if (length < 2) {
        printf("Not defined for arrays with <2 elements\n");
        return NULL;
    }
    int *fresh = malloc(sizeof(int) * (length - 1));
    if (fresh == NULL) {
        printf("Could not allocate fresh memory\n");
        return NULL;
    }
    // do the pairwise sum into "fresh"
    for (int i = 0; i < length; i++) {
        fresh[i] = array[i] + array[i+1];
    }
    return fresh;
}

// Print an array of ints with space separators
void print_array(int *array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    putchar('\n'); // print single newline to stdout
}

int main() {
    int array[] = {4, 7, 2, 3, 7};
    int *pairsum1 = pairwise_sum(array, 5);
    if (pairsum1 == NULL) {
        return 1; // error
    }
    print_array(pairsum1, 4);
    free(pairsum1);

    int *pairsum2 = pairwise_sum(pairwise_sum(array, 5), 4);
    if (pairsum2 == NULL) {
        return 1; // error
    }
    print_array(pairsum2, 3);
    free(pairsum2);

    return 0;
}
