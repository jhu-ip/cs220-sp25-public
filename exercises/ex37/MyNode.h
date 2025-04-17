#ifndef MYNODE_H
#define MYNODE_H

// A single node holding payload data of any type

template <typename T>
class MyNode {

 public:
  
  T data;          // payload
  MyNode<T> *next; // pointer to following node

  // two-argument constructor
  MyNode<T>(int d, MyNode<T>* n) : data(d), next(n) { }

};  

#endif
