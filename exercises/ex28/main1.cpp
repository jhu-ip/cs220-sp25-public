#include "grade_list.h"
#include <iostream>

/**
 * No TODOs here.  Just an example of how to use GradeList.
 */

using std::cout;
using std::endl;

int main() {
  GradeList gl(3);

  gl.add(20.0); gl.add(30.0); gl.add(40.0);
  gl.add(15.0); gl.add(15.0); gl.add(75.0);
  gl.add(85.0); gl.add(40.0); gl.add(42.0);

  cout << "min value was: " << gl.min() << " (should be 15)" << endl;
  cout << "length is: " << gl.length() << " (should be 12)" << endl;
  cout << "size is: " << gl.size() << " (should be 9)" << endl;

  gl.clear();
  double vals[] = {12, 15, 10, 13, 18, 8, 15};
  gl.add(5, vals);
  cout << "min value is: " << gl.min() << " (should be 10)" << endl;
  cout << "length is: " << gl.length() << " (should be 8)" << endl;
  cout << "size is: " << gl.size() << " (should be 5)" << endl;

  return 0;
}
