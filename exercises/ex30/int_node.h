//int_node.h

#ifndef INT_NODE_H
#define INT_NODE_H

class int_node {

 private:

  int       data;  //the payload stored in this node
  int_node* next;  //the pointer to node after this one

 public:

  //constructors
  int_node(int value, int_node* ptr = nullptr): data(value), next(ptr) { }

  //getters
  int get_data() const         { return data; }
  int_node* get_next() const   { return next; }

  //setters
  void set_data(int value)     { data = value; }
  void set_next(int_node* ptr) { next = ptr; }

};

#endif
