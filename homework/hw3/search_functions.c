// search_functions.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
//
//


#include <stdio.h>
#include "search_functions.h"



/* 
 * Given a filename and a MAX_SIZExMAX_SIZE grid to fill, this function 
 * populates the grid and returns n, the number of rows. This function 
 * also must fill in the variable pointed to by the pointer m with
 * number of columns.
 * If filename_to_read_from can't be opened, this function returns -1.
 * If the file contains an invalid grid, this function returns -2.
 */
int populate_grid(int *m, char grid[][MAX_SIZE], char filename_to_read_from[]){

  return -1; // replace this stub

}


/* 
 * <Replace this with your own useful comment.> 
 */
int find_dd(char grid[][MAX_SIZE], int n, int m, char word[], FILE *write_to){

  return -1; // replace this stub

}


/* 
 * <Replace this with your own useful comment.> 
 */
int find_du (char grid[][MAX_SIZE], int n, int m, char word[], FILE *write_to){

  return -1; // replace this stub

}


/* 
 * <Replace this with your own useful comment.> 
 */
int find_ad (char grid[][MAX_SIZE], int n, int m, char word[], FILE *write_to){

  return -1; // replace this stub

}


/* 
 * <Replace this with your own useful comment.> 
 */
int find_au (char grid[][MAX_SIZE], int n, int m, char word[], FILE *write_to){

  return -1; // replace this stub

}


/* 
 * <Replace this with your own useful comment.> 
 */
int find_all  (char grid[][MAX_SIZE], int n, int m, char word[], FILE *write_to) {

  return -1; // replace this stub

} 


/*
 * Reads lhs and rhs character by character until either reaches eof.
 * Returns true if the files can be read and the two files match
 * character by character. Returns false if two files either can't be
 * opened or don't match. The definition of this function is provided 
 * for you.
 */
int file_eq(char lhs_name[], char rhs_name[]) {
  FILE* lhs = fopen(lhs_name, "r");
  FILE* rhs = fopen(rhs_name, "r");

  // don't compare if we can't open the files
  if (lhs == NULL || rhs == NULL) return 0;

  int match = 1;
  // read until both of the files are done or there is a mismatch
  while (!feof(lhs) || !feof(rhs)) {
	if (feof(lhs) ||                      // lhs done first
		feof(rhs) ||                  // rhs done first
		(fgetc(lhs) != fgetc(rhs))) { // chars don't match
	  match = 0;
	  break;
	}
  }
  fclose(lhs);
  fclose(rhs);
  return match;
}

/*
 * Helper function to print out the grid.
 */
void print_grid(char grid[][MAX_SIZE], int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] != '\0')
	printf ("%c", grid[i][j]);
    }
    printf ("\n");
  }
}
