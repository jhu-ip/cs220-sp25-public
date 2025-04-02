#include <iostream>
#include <cassert>
#include "int_set.h"

using std::cout;
using std::endl;

int main() {
  int_set s;
  cout << "starting contents: " << s << endl;

  assert(s.add(1));
  assert(s.add(5));
  assert(s.add(2));
  cout << "just added 1,5,2: " << s << endl;
  cout << "s size is " << s.get_size() << endl;

  assert(!s.add(1));
  assert(!s.add(2));
  assert(!s.add(5));
  cout << "just attempted to re-add 1,2,5: " << s << endl;
  cout << "s size is " << s.get_size() << endl;


  /*
  //This section requires the += operator!

  s += 4;
  cout << "just used operator+= 4 on s: " << s << endl;
  s += 5;
  cout << "just used operator+= 5 on s: " << s << endl;
  cout << "s += 6 results in " << (s += 6) << endl;
  cout << "size of s is " << s.get_size() << endl;
  */

  /*
  //This section requires the copy constructor!

  int_set v(s);   // calls copy constructor
  cout << "copy of s called v looks like this: " << v << endl;
  v += 3;
  cout << "v looks like this after operator += 3 to it: " << v << endl;
  cout << "s still looks like this: " << s << endl;
  */


  //This section uses clear and get_size functions!
  s.clear();
  cout << "just cleared s: " << s << endl;
  cout << "size of s is " << s.get_size() << endl;


  //Uncomment the line below once v is declared above
  //cout << "and v's contents are still: " << v << endl;


  /*
  //This section requires the assignment operator!
  int_set t;
  t.add(27);
  cout << "made a new set t and its contents are: " << t << endl;
  s = t;  // copy t to s, using assignment operator not copy constructor
  cout << "just made s store a copy of t using =, and s looks like: " << s << endl;
  s.add(14);
  cout << "called s.add(14) and now s looks like: " << s << endl;
  cout << "and t's contents are still: " << t << endl;
  t.clear();
  cout << "cleared t and s's contents are still: " << s << endl;
  cout << "but t now looks like this: " << t << endl;
  cout << "and v's contents are still: " << v << endl;
  v.clear();
  */

  //NOTE: If the final section above is uncommented, you'll also need the
  //destructor implmented to avoid memory leaks, since s isn't
  //explicitly cleared at the end of this program.
  
  return 0;
}
