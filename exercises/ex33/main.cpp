// 601.220 - example of inheritance, overriding and abstract class

#include "Aclass.h"
#include "Bclass.h"
//#include "Cclass.h"
#include <iostream>

using std::cout;
using std::endl;

int main (void) {
  A aobj(10);
  B bobj(20);
  

  // Part 2 
  cout << aobj.toString() << endl;
  cout << bobj.toString() << endl;
  aobj.seta(13);
  aobj = bobj;
  cout << aobj.toString() << endl;
  bobj.setb(27);
  bobj = aobj;
  cout << bobj.toString() << endl;

  // Part 3
  cout << aobj.fun();
  bobj.seta(1);
  bobj.setd(2);
  cout << bobj.fun() << endl;
  bobj.setb(2);
  cout << bobj.fun() << endl;

  // Part 4
  //C cobj(11);
  //cout << cobj.toString() << endl;
  //cobj.sete(18);
  //cout << cobj.toString() << endl;
  //cout << cobj.fun() << endl;
  
  return 0;
  
}


