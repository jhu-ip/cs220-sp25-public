#include <stdio.h>
#include <string.h>

/* Transpose from a 3x5 array (start) 
   into a 5x3 array (end) of integers.
 */
void transpose(int start[][5], int end[][3]) {

  int d1 = 3, d2 = 5;

  for (int r = 0; r < d1; r++)
    for (int c = 0; c < d2; c++) {
      end[r][c] = start[c][r]; 
    }
}

/* Print a 2D array of integers
 */
void print(int table[][3], int rows, int cols) {
  for (int r = 1; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      printf("%d ", table[r][c]);
    }
    printf("\n");
  }
}


int main() {

  int one[3][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
  int two[5][3] = {0}; 

  printf("2nd table:\n");
  print(two, 5, 3);
  printf("2nd after transpose:\n");
  transpose(one, two);
  print(two, 5, 3);
  return 0;
}
