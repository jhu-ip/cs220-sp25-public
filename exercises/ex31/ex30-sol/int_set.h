#ifndef INT_SET_H
#define INT_SET_H

#include <iostream>
#include "int_node.h"

/* Class to represent a mathematical set of ints (like std::set<int>,
   but we're writing this one ourselves).  Recall that set objects may
   never contain duplicate values, so we must avoid adding new items
   that are equal to existing items in the set.  To facilitate checking
   for duplicates, we store the items in a SORTED linked list of
   int_nodes. The sort is in ascending order by < on ints.
*/
class int_set {

 private:

  int_node* head;
  int       size;

 public:

  //constructor to create an empty list
  int_set(): head(nullptr), size(0) { }

  //copy constructor to make a "deep copy" of the set
  int_set(const int_set& other);

  //destructor
  ~int_set();

  //report the current size of the set (i.e. number of elements in it)
  int get_size() const { return size; }
  
  //remove all existing items from set
  void clear();

  //insert the given item into the set, provided it's not a duplicate
  //return true if insertion successful, false otherwise
  bool add(int new_value);
 

  // alternative way to call add, returning this updated int_set
  int_set& operator+=(int new_value);


  // overload the assignment operator to make a deep copy and return
  // a reference to this updated int_set
  int_set& operator=(const int_set& other);


  //output items in set, comma-and-space-separated within curly braces
  //E.g.  {1, 2, 3}  or {}
  friend std::ostream& operator<<(std::ostream& os, const int_set& s);


};

#endif
