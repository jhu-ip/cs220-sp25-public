#include "grade_list.h"
#include <iostream>
#include <cassert>

/**
 * Hint: resolve the TODOs in grade_list.h first.
 * 
 * TODO: This program is *trying* to insert several
 * grades into a GradeList, print the lowest, and
 * then multiple each value by 10.
 * But it doesn't compile. Think about why it
 * doesn't work and fix it by modifying the GradeList
 * class definition (not the code below). Don't change any
 * private fields to be public in GradeList!
 */

using std::cout;
using std::endl;


int main() {

  GradeList gl;

  gl.add(20.0); gl.add(30.0); gl.add(40.0);
  gl.add(15.0); gl.add(15.0); gl.add(75.0);
  gl.add(85.0); gl.add(40.0); gl.add(42.0);

  cout << "min value was: " << gl.min() << " (should be 15)" << endl;
  cout << "length is: " << gl.length() << " (should be 16)" << endl;
  cout << "size is: " << gl.size() << " (should be 9)" << endl;

  for (double * it = gl.begin(); it != gl.end(); ++it) {
    *it *= 10; 
  }

  cout << "min value is: " << gl.min() << " (should be 150)" << endl;
  cout << "length is: " << gl.length() << " (should be 16)" << endl;
  cout << "size is: " << gl.size() << " (should be 9)" << endl;

  return 0;
}
