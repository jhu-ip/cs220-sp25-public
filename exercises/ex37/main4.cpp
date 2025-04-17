#include "MyList.h"
#include <vector>

using std::cout;
using std::endl;

template<typename T>
std::ostream& operator<<(std::ostream& os, const MyList<T>& list) {
  for(typename MyList<T>::const_iterator cit = list.cbegin();
      cit != list.cend(); 
      ++cit) {
    os << *cit << ' ';
  }

  return os;
}


int main() {


  // The following attempt at constructing a linked list from a vector 
  // won't compile because it requires that MyList<T> define a 
  // constructor taking a begin and end iterator. You need to
  // implement the constructor in MyList.h (see TODO Part 5).
  std::vector< int > v = {1, 2, 3, 4, 5, 6};
  MyList<int> mli(v.begin(), v.end());

  cout << mli << endl;

  return 0;
}
