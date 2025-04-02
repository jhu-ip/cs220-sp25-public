#include <iostream>
#include <cassert>
#include <string>
#include "my_set.h"

using std::cout;
using std::endl;


int main() {
  my_set<int> s;

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

  s += 4;
  cout << "just operator+= 4 to s: " << s << endl;
  s += 5;
  cout << "just operator+= 5 to s: " << s << endl;
  cout << "s += 6 results in " << (s += 6) << endl;
  cout << "s size is " << s.get_size() << endl;

  my_set<int> t(s);   // calls copy constructor
  cout << "t copy looks like this: " << t << endl;
  t += 3;
  cout << "t looks like this after add 3: " << t << endl;
  cout << "s looks like this after add 3 to t: " << s << endl;

  s.clear();
  cout << "just cleared s: " << s << endl;
  cout << "s size is " << s.get_size() << endl;
  cout << "and t's contents are still: " << t << endl;


  s = t;  // copy t to s
  cout << "s copy of t: " << s << endl;
  s.add(14);
  cout << "s added 14: " << s << endl;
  cout << "and t's contents are still: " << t << endl;
  t.clear();
  cout << "cleared t and s's contents are still: " << s << endl;



  cout << "\n\nNOW CREATING SET OF STRINGS! \n" << endl;
  my_set<std::string> alpha;
  alpha.add("hello");
  alpha.add("world");
  alpha.add("hello");
  alpha.add("mars");
  cout << "Now alpha contains: " << alpha << endl;
  cout << "And the size of alpha is: " << alpha.get_size() << endl;

  return 0;
}
