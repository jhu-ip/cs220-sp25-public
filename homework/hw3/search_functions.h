// search_functions.h
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>
//
//
// NOTE: all the functions declared in this file (those 
// required by the assignment and those added by you) 
// should be implemented in search_functions.c.



#ifndef SEARCH_FUNCTIONS_H
#define SEARCH_FUNCTIONS_H


/*
 * A useful named constant representing the maximum grid size.
 * This constant will be available for use in any file that 
 * contains the line #include "search_functions.h".
 */
#define MAX_SIZE 10



/*
 * Given a filename and a MAX_SIZExMAX_SIZE grid to fill, this function 
 * populates the grid and returns n, the number of rows. This function 
 * would also fill in variable pointed to by pointer m with number of
 * columns.
 * If filename_to_read_from can't be opened, this function returns -1. 
 * If the file contains an invalid grid, this function returns -2.
 */
int populate_grid(int * m, char grid[][MAX_SIZE], char filename_to_read_from[]); 


/*
 * Each of these 4 functions returns the number of times the given 
 * word string was found in the grid facing the direction indicated
 * in the function name. Parameter n and m indicate num of rows and cols
 * respectively. The function sends corresponding output to the specified 
 * file pointer, which already points to an open stream. Output lines 
 * must appear in order of the first character's appearance in a 
 * left-to-right scan of each row beginning with row 0.
 */
int find_dd(char grid[][MAX_SIZE], int n, int m, char word[], FILE *write_to); 
int find_du (char grid[][MAX_SIZE], int n, int m, char word[], FILE *write_to); 
int find_ad (char grid[][MAX_SIZE], int n, int m, char word[], FILE *write_to); 
int find_au   (char grid[][MAX_SIZE], int n, int m, char word[], FILE *write_to); 


/*
 * This function is similar to the other 4 find_ functions above, 
 * but reports ALL appearances of the given word, in the required 
 * DD, DU, AD, AU order.
 */
int find_all  (char grid[][MAX_SIZE], int n, int m, char word[], FILE *write_to); 



/*
 * Reads lhs and rhs character by character until either reaches eof.
 * Returns true if the files can be read and the two files match
 * character by character. Returns false if two files either can't be
 * opened or don't match. The definition of this function is provided
 * for you.
 */
int file_eq(char lhs_name[], char rhs_name[]);

void print_grid(char grid[][MAX_SIZE], int n, int m);

#endif
