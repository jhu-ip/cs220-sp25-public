#ifndef GRADE_LIST_H
#define GRADE_LIST_H

/**
 * Writing C++ classes:
 * 
 * This exercise uses a dynamically allocated and resized 
 * array to implement a GradeList class. You will be
 * writing a customized constructor, a destructor, and
 * using new and delete for memory allocation.
 * 
 * Look at the files provided:
 * 
 *   grade_list.h
 *   grade_list.cpp
 *   main1.cpp
 *   main2.cpp
 * 
 * Read all the comments and fix all the issues
 * highlighted with "TODO"
 * 
 * Also provided is a Makefile to make it easier to
 * build the different main programs.  The targets
 * are called main1 and main2.
 */

#include <vector>

class GradeList {

 public:

  // TODO: In grade_list.cpp, write this constructor that has a 
  // parameter indicating the starting length of the array. 
  // See main1.cpp for sample usage.
  GradeList(int capacity);

  // TODO: define this in grade_list.cpp. If the array is full,
  // resize it by doubling it's length. Do not use realloc!
  void add(double grade);

  // TODO: define this overloaded function in grade_list.cpp
  // Add the specified number of values from an array of 
  // grades to this object.
  void add(int howmany, double * grades);

  // TODO: write a function (in grade_list.cpp) to clear the list
  // of all values, making the array as small as possible (capacity 1)
  void clear();


  // These functions are written for you, for convenience.
  int length() { return capacity; }
  int size() { return count; }
  double min();  // defined in grade_list.cpp


  // TODO: write begin and end functions to mimic an iterator
  // using actual pointers


private:

  // The following fields MUST REMAIN PRIVATE in
  // your solution

  double * grades;  // dynamically allocated array
  int capacity;     // declared size of the array
  int count;        // number of grades in the array
};

#endif
