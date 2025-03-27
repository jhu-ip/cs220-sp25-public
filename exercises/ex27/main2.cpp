#include "grade_list.h"
#include <iostream>
#include <cassert>

/**
 * Hint: resolve the TODOs in grade_list.h first.
 * 
 * TODO: This program is *trying* to insert several
 * grades into a GradeList then print the lowest.
 * But it doesn't compile. Think about why it
 * doesn't work and fix it. You can(should) add to the
 * GradeList class, but don't change any private
 * fields to be public!
 */

using std::cout;
using std::endl;

int main(void) {

  GradeList gl;

  gl.add(20.0); gl.add(30.0); gl.add(40.0);
  gl.add(15.0); gl.add(15.0); gl.add(75.0);
  gl.add(85.0); gl.add(40.0); gl.add(42.0);

  double min_so_far = 100.0;
  for (size_t i = 0; i < gl.grades.size(); i++) {
    if (gl.grades[i] < min_so_far) {
      min_so_far = gl.grades[i];
    }
  }

  cout << "Minimum grade is: " << min_so_far << endl;
  assert (min_so_far == gl.percentile(0));
  return 0;
}
