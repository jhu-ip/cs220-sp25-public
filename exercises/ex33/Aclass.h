#ifndef _ACLASS_H
#define _ACLASS_H

#include <iostream>
#include <string>
#include <sstream>

class A { // base class

private: 
  int a;

protected:
  double d;

public: 
  A(int val = 0, double num = 0): a(val), d(num) { }
  void seta(int val) { a = val; }
  void setd(double dval) { d = dval; }
};

#endif
