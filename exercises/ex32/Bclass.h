#include <iostream>

#ifndef _BCLASS_H
#define _BCLASS_H

#include "Aclass.h"

class B : public A {
private:
  int b;

public:
  B(int val = 0): b(val) { };  // automatically sets a & d to 0 w/ A()
  B(int bval, int aval, double dval): A(aval, dval), b(bval) {
     d = 17; 
     a = 27; 
  };
  ~B() { std::cout << "B obj killed" << std::endl; } ;
  void setb(int val) { b = val; };
  void display() { std::cout << "non-virtual display B " << std::endl; show(); };
  void test() { std::cout << "test B" << std::endl; };
  void show() { A::show(); std::cout << "B is " << b << std::endl; test(); };

};

#endif
