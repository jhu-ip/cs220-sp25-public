#include "MyList.h"

using std::cout;
using std::endl;

// The following attempt at overloading operator<< for
// MyList<T> won't compile because it requires that
// MyList<T> define const_iterator and the corresponding
// accessor functions -- cbegin() and cend().
//
// Implement them using a nested class as described in
// TODO Part 4a in MyList.h.  A  skeleton is already
// provided for you there.               
template<typename T>
std::ostream& operator<<(std::ostream& os, const MyList<T>& list) {
  for(typename MyList<T>::const_iterator cit = list.cbegin();
      cit != list.cend(); 
      ++cit) {
    os << *cit << ' ';


    // TODO Part 4b: 
    // Once you have completed the const_iterator in MyList.h
    // and confirmed the main function can print the list, 
    // try uncommenting the following line and confirm that 
    // the compiler will NOT allow you to modify the elements 
    // via the const_iterator.

    // (*cit)++;
  }

  return os;
}


int main() {

  MyList<int> mli;
  mli.insertAtTail(2);
  mli.insertAtTail(4);
  mli.insertAtTail(6);
  mli.insertAtTail(8);

  // Print list twice
  cout << mli << endl;
  cout << mli << endl;

  return 0;
}
