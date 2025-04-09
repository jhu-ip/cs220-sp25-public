#ifndef _BCLASS_H
#define _BCLASS_H

#include <iostream>
#include <string>
#include "Aclass.h"

class B : public A {

private:
  int b;

public:
  B(int val = 0): b(val) { }  // automatically sets a & d to 0 w/ A()
  B(int bval, int aval, double dval): A(aval, dval), b(bval) {
     d = 17; 
  }
  void setb(int val) { b = val; }
};


#endif
