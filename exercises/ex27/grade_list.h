#ifndef GRADE_LIST_H
#define GRADE_LIST_H

/**
 * Writing C++ classes:
 * 
 * 1. class {...}; definition goes in a .h file
 * 
 * 2. Very simple member functions can be implemented
 *    "inline" -- inside the class definition.  For
 *    longer member functions, put a prototype in the
 *    class definition, then define the function in a
 *    .cpp file.
 * 
 *    e.g. for GradeList, "add" is defined inline,
 *    but "percentile" is defined in grade_list.cpp
 * 
 * 3. Functions declared within the class are "member
 *    functions."  Variables declared in the class are
 *    "fields."  We access member functions and fields
 *    in the same way we accessed fields of a struct.
 *    E.g.
 * 
 *        GradeList gl;
 *        gl.add(40.5);
 *        gl.add(41.5);
 *        cout << gl.mean() << endl;
 * 
 * 4. "public:" and "private:" determine member
 *    accessibility.  A "private" member can only be
 *    used from within a member function of the same
 *    class.  "public" members are always accessible.
 * 
 * Look at the files provided:
 * 
 *   grade_list.h
 *   grade_list.cpp
 *   main1.cpp
 *   main2.cpp
 *   main3.cpp
 * 
 * Read all the comments and fix all the issues
 * highlighted with "TODO"
 * 
 * Also provided is a Makefile to make it easier to
 * build the different main programs.  The targets
 * are called main1, main2 and main3.
 */

#include <vector>

class GradeList {

 public:

  // Explicitly-defined default constructor
  GradeList() : grades(), is_sorted(false) { }

  void add(double grade) {
    // When accessing a field of the same class,
    // we refer to it by name.  No need to write
    // "this.grades", "self.grades" or the like
    grades.push_back(grade);
    is_sorted = false;
  }

  // Defined in grade_list.cpp
  double percentile(double percentile);

  // TODO: define this function in grade_list.cpp
  double mean(void);

  // TODO: define this function in grade_list.cpp
  // Hint: median = 50th percentile
  double median(void);



 private:

  // The following fields MUST REMAIN PRIVATE in
  // your solution

  std::vector<double> grades;
  bool is_sorted;
};

#endif
