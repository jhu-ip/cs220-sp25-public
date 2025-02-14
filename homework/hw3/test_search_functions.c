// test_search_functions.c
// <STUDENT: ADD YOUR INFO HERE: name, JHED, etc.>



#include <stdio.h>
#include <assert.h>
#include "search_functions.h"


/* 
 * Declarations for tester functions whose definitions appear below.
 * (You will need to fill in the function definition details, at the
 * end of this file, and add comments to each one.) 
 * Additionally, for each helper function you elect to add to the 
 * provided search_functions.h, you will need to supply a corresponding
 * tester function in this file.  Add a declaration for it here, its
 * definition below, and a call to it where indicated in main.
 */
void test_file_eq();      // This one is already fully defined below.
void test_populate_grid();
void test_find_dd();
void test_find_du();
void test_find_ad();
void test_find_au();
void test_find_all();


/*
 * Main method which calls all test functions.
 */
int main() {
  printf("Testing file_eq...\n");
  test_file_eq();
  printf("Passed file_eq test.\n\n");

  printf("Running search_functions tests...\n");
  test_populate_grid();
  test_find_dd();
  test_find_du();
  test_find_ad();
  test_find_au();
  test_find_all();

  /* You may add calls to additional test functions here. */

  printf("Passed search_functions tests!!!\n");
}



/*
 * Test file_eq on same file, files with same contents, files with
 * different contents and a file that doesn't exist.
 * Relies on files test1.txt, test2.txt, test3.txt being present.
 */
void test_file_eq() {
  FILE* fptr = fopen("test1.txt", "w");
  fprintf(fptr, "this\nis\na test\n");
  fclose(fptr);

  fptr = fopen("test2.txt", "w");
  fprintf(fptr, "this\nis\na different test\n");
  fclose(fptr);

  fptr = fopen("test3.txt", "w");
  fprintf(fptr, "this\nis\na test\n");
  fclose(fptr);

  assert( file_eq("test1.txt", "test1.txt"));
  assert( file_eq("test2.txt", "test2.txt"));
  assert(!file_eq("test2.txt", "test1.txt"));
  assert(!file_eq("test1.txt", "test2.txt"));
  assert( file_eq("test3.txt", "test3.txt"));
  assert( file_eq("test1.txt", "test3.txt"));
  assert( file_eq("test3.txt", "test1.txt"));
  assert(!file_eq("test2.txt", "test3.txt"));
  assert(!file_eq("test3.txt", "test2.txt"));
  assert(!file_eq("", ""));  // can't open file
}


void test_populate_grid(){

  assert(1);  //replace this stub!

}


void test_find_dd(){

  assert(1);  //replace this stub!

}


void test_find_du(){

  assert(1);  //replace this stub!
}


void test_find_ad(){

  assert(1);  //replace this stub!

}


void test_find_au(){

  assert(1);  //replace this stub!

}


void test_find_all(){

  assert(1);  //replace this stub!

}

