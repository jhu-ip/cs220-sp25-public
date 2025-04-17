#include "MyList.h"

using std::cout;
using std::endl;



// The following attempt at overloading operator<< for
// MyList<T> won't compile because it requires that
// MyList<T> define iterator and the corresponding
// accessor functions -- begin() and end().
//
// Implement them using a nested class as described in
// TODO Part 3a in MyList.h.  A  skeleton is already
// provided for you there.

template<typename T>
std::ostream& operator<<(std::ostream& os, MyList<T>& list) {
  for(typename MyList<T>::iterator it = list.begin();
      it != list.end(); 
      ++it) {
    os << *it << ' ';

    // TODO Part 3b:
    // Once you have completed the iterator in MyList.h, confirm
    // that you can modify the list via the iterator by
    // un-commenting the following line and re-running.  
    // You should see the list change.

    // (*it)++;
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
