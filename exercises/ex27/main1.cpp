#include "grade_list.h"
#include <iostream>

/**
 * TODO: Uncomment the calls to mean and median once you've implemented those
 * functions.
 */

using namespace std;

int main(void) {

  GradeList gl;

  gl.add(20.0); gl.add(30.0); gl.add(40.0);
  gl.add(15.0); gl.add(15.0); gl.add(75.0);
  gl.add(85.0); gl.add(40.0); gl.add(42.0);

  cout << "80th percentile was: " << gl.percentile(80.0) << endl;
  // cout << "mean was: " << gl.mean() << endl;
  // cout << "median was: " << gl.median() << endl;
  return 0;
}
