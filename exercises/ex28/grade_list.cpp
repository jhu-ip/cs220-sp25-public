#include "grade_list.h"
#include <cassert>

// You will add function definitions to this file.
// See TODOs in grade_list.h.

double GradeList::min() {
  assert(count > 0);   // no values otherwise
  double minval = grades[0];
  for (int i = 1; i < count; i++) {
    if (grades[i] < minval)
      minval = grades[i];
  }
  return minval;
}

//////////// things to be added for part 2  /////////////////

// TODO: write a constructor (in grade_list.cpp) that has a 
// parameter indicating the starting length of the array. 




// TODO: Add the given grade to the grades list. If the array is full,
// resize it by doubling its length. Do not use realloc!




// TODO: Add the specified number of values from an array of 
// grades to this object.




// TODO: write a function (in grade_list.cpp) to clear the list
// of all values, making the array as small as possible



