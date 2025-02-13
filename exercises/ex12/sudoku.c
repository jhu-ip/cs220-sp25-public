#include <stdio.h>
#include "sudokuHelpers.h"


int main(int argc, char * argv[]) {

  if (argc < 2) {
    fprintf(stderr, "invalid program call\n");
    return 1;  // incorrect program usage
  }
  FILE* infile = fopen(argv[1], "r");
  if (infile == NULL) {
    fprintf(stderr, "could not open file: %s\n", argv[1]);
    return 2;  // file open failure
  }

  int puzzle[SIZE][SIZE];

  for (int i = 0; i < SIZE; i++)
    for (int j = 0; j < SIZE; j++) {
      fscanf(infile, "%d", &puzzle[i][j]);
      if (puzzle[i][j] < 0 || puzzle[i][j] > SIZE) {
        fprintf(stderr, "invalid input for cell\n");
        return 3; // invalid input error
      }
    }

  if (checkRows(puzzle) && checkCols(puzzle) && checkCubes(puzzle))
    printf("puzzle is correctly solved\n");
  else
    printf("puzzle is not [correctly] solved\n");
  return 0;
}
