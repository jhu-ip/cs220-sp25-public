#ifndef LIST_H
#define LIST_H


typedef struct _node {
  char data;
  struct _node * next;
} Node;                           // Node is a linked list node that holds char data



Node * create_node(char);          // put char into a newly created node

void print_list(const Node *);     // output the list iteratively
void print_rec(const Node *);      // output the list recursively
void reverse_print(const Node *);  // output the list in reverse

long length(const Node *);         // count and return the number of elements in the List
void clear_list(Node **);          // get rid of (deallocate) entire list

void add_after(Node *, char);      // add char immediately after existing node
void add_front(Node **, char);     // add char to beginning of list


// EXERCISE
char remove_after(Node *);         // remove node after current, return char
char remove_front(Node **);        // remove first node, if any, return char


// EXERCISE
void remove_all(Node **, char);    // remove all occurrences of a particular character


// EXERCISE
// insert in order if not duplicate, assumes list is ordered!!
// return the address of the Node containing the inserted character
Node * insert(Node **, char);




// ---------- Other functions you may want to implement ----------

// insert char at the end of the list
void add_tail(Node **, char); 
void add_tail_rec(Node **, char); // recursive version

// locate a value in the list, return pointer to containing node, or NULL
Node * find(Node *, char);

// remove char from list if it is there, return 1 success, 0 failure
int remove_char(Node **, char);   
int remove_char_rec(Node **, char);   // recursive version

// replace first occurrence of old with new, return 1 success, 0 failure
int replace(Node *, char old, char new); 


#endif

