#include "int_set.h"


//copy constructor to make a "deep copy" of the set
int_set::int_set(const int_set& orig) : int_set() {

  //TO DO: FILL IN YOUR CODE HERE
  for( const int_node *node=orig.head ; node ; node=node->get_next() )
    add( node->get_data() );
}

//destructor
int_set::~int_set(){

  //TO DO: FILL IN YOUR CODE HERE
  clear();
  
}

//remove all existing items from set
void int_set::clear(){
  //deallocate all nodes in the list
  int_node *cur = head;
  while (cur) {
	int_node* temp = cur;
	cur = cur->get_next();
	delete temp;
  }
  //reset instance variables
  head = nullptr;
  size = 0;
}

//insert the given item into the set, provided it's not a duplicate
//return true if insertion successful, false otherwise
//RESTRICTION: use only < and == on the data within nodes (not <=, >, >=, !=)
bool int_set::add(int new_value) {

  //first, abort if new_value would be a duplicate when added to set
  int_node* cur = head;
  while (cur) {
    if (cur->get_data() == new_value) {
      return false;
    }
    cur = cur->get_next();
  }

  //next, create new node to hold the new value
  int_node* new_node = new int_node(new_value);
  if (!new_node) {  //allocation failed!
	return false; 
  }

  if (!head) { //list is currently empty
	head = new_node;
	size++;
	return true;
  }
  if (new_value < head->get_data()) { //new_node is smallest
        new_node->set_next(head);
	head = new_node;
	size++;
	return true;
  }

  //new_node should go somewhere after 1st node, so let's locate
  //first node whose data larger than new_node's.  But we must
  //be careful not to fall off end of list!
  cur = head;
  //So we'll stop looping when either cur is pointing to last node
  //in the list, or cur has advanced as far into this list as it can,
  //while still pointing to a node with a value smaller than new one
  while (cur->get_next() && (cur->get_next()->get_data() < new_value)) {
    cur = cur->get_next();
  }
  new_node->set_next(cur->get_next());  //may be nullptr, but that's ok too
  cur->set_next(new_node);
  size++;
  return true;
}
 
//Overload the += operator using the add method
//return a reference to this int_set for consistency
int_set& int_set::operator+=(int new_value) {

  //TO DO: FILL IN YOUR CODE HERE
  add( new_value);
  
  return *this;    //for consistency - assignment ops return the value assigned
}


// overload the assignment operator to make a deep copy and return
// a reference to this updated int_set
int_set& int_set::operator=(const int_set& other) {

  //TO DO: FILL IN YOUR CODE HERE
  if (this != &other) { // prevent assigning to itself
    clear();
    for( const int_node *node=other.head ; node ; node=node->get_next() )
      add( node->get_data() );
  }
  return *this;
}


//output items in set, comma-and-space-separated within curly braces
//E.g.  {1, 2, 3}  or {}
//NOTE that the 'friend' keyword doesn't appear outside the class,
//and that we don't pre-pend the name of this method with int_set::,
//since it's not an actual member of the class
std::ostream& operator<<(std::ostream& os, const int_set& s){

  //TO DO: FILL IN YOUR CODE HERE
  os << "{";
  int_node* node = s.head;
  while( node )
    {
      os << node->get_data();
      node = node->get_next();
      if( node ) os << ", ";
    }
  os << "}";

  return os;
}
