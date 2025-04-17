#include "MyList.h"

using std::cout;
using std::endl;

//
// No to-do items here except to read, understand, compile, and run
// this code, which does not use iterators.
//

int main() {

  MyList<int> mli;
  mli.insertAtTail(2);
  mli.insertAtTail(4);
  mli.insertAtTail(6);
  mli.insertAtTail(8);

  for(const MyNode<int>* cur = mli.get_head();
      cur != nullptr; 
      cur = cur->next) {
    cout << cur->data << " ";
  }
  cout << endl;
    
  // Just because the .get_head() accessor returns a const MyNode*
  // doesn't mean I can't modify the list!!
  mli.get_head()->next->data = 999;

  for(const MyNode<int>* cur = mli.get_head();
      cur != nullptr; 
      cur = cur->next) {
    cout << cur->data << " ";
  }
  cout << endl;
    
  return 0;
}
