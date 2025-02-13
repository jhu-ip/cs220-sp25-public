#ifndef SUDOKUHELPERS_H
#define SUDOKUHELPERS_H

#define SIZE 9  // pre-processor substitution, sort of like a constant

// check if a 9-item group in a Sudoku puzzle is complete
// a group could be a row, a column, or a cube
int check(int * group);

// make a 1D array from a column of a 2D array (SIZE x SIZE )
int* makeCol(int *table);

// make a 1D array from a cube of a 2D array (SIZE x SIZE )
int* makeCube(int *table);

// check each row
int checkRows(int table[][SIZE]);

// check each column
int checkCols(int table[][SIZE]);

// check each cube
int checkCubes(int table[][SIZE]);

#endif
