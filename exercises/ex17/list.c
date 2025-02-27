#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

// put char into a newly created node
Node * create_node(char ch) {
  Node * node = (Node *) malloc(sizeof(Node));
  assert(node); //confirm malloc didn't fail

  node->data = ch;
  node->next = NULL;
  return node;
}

// output the list iteratively
void print_list(const Node * cur) {
  while (cur != NULL) {
    printf("%c ", cur->data);
    cur = cur->next;  // advance to next node
  }
}

// output the list recursively
void print_rec(const Node * head) {
  if (head != NULL) {
    printf("%c ", head->data);
    print_rec(head->next);
  }
}

// output the list in reverse (recursive)
void reverse_print(const Node * head) {
  if (head != NULL) {  // equivalent: if (head)
    reverse_print(head->next);
    printf("%c ", head->data);
  }
}

// count and return the number of elements in the List (recursive)
long length(const Node * head) {
  if (head == NULL)
    return 0;
  return 1 + length(head->next);
}

// get rid of (deallocate) entire list, recursively from end to start
void clear_list(Node ** list_ptr) {
  if (*list_ptr != NULL) {
    clear_list( &((*list_ptr)->next));
    free(*list_ptr);
    *list_ptr = NULL;
  }
}

// add char immediately after existing node
void add_after(Node * node, char val) {
  if (node == NULL)
    return;
  Node * n = create_node(val);
  n->next = node->next;
  node->next = n;
}

// add char to beginning of list
void add_front(Node ** list_ptr, char val) {
  Node * n = create_node(val);
  n->next = *list_ptr;
  *list_ptr = n;
}

// EXERCISE
// remove node after current, return removed char, or '?' if no node
char remove_after(Node * node) {

  // not yet implemented
  return '?';  // replace this stub

}

// EXERCISE
// remove first node, if any, return removed char or '?' if no node
char remove_front(Node ** list_ptr) {

  // not yet implemented
  return '?';  // replace this stub

}

// EXERCISE
// remove all occurrences of a particular character
void remove_all(Node ** list_ptr, char val) {

  // not yet implemented - hint: recursion

}

// EXERCISE
// insert in order (assumes list is ordered)!!
// return the address of the node containing the character inserted
Node * insert(Node ** list_ptr, char val) {

  // not yet implemented - hint: recursion
  return NULL; // replace this stub

}



// ---------- Other functions you may want to implement ----------

// insert char at end of list
void add_tail(Node ** list_ptr, char val) {

  // not yet implemented

}


// insert char at end of list (recursive)
void add_tail_rec(Node ** list_ptr, char val) {

  // not yet implemented

}

// find specfied val in the list, return pointer to first node in list
// that contains it, or NULL if val is not present
Node* find(Node * node, char value) {

  // not yet implemented
  return NULL;  // replace this stub

}

// remove 1st occurrence of char from list if there, return 1 success, 0 failure
int remove_char(Node ** list_ptr, char val) {

  // not yet implemented
  return 0;

}

// recursive version of removing first occurrence
int remove_char_rec(Node ** list_ptr, char val)  {

  // not yet implemented
  return 0;  // replace this stub

}

// replace first occurrence of old with new, return 1 success, 0 failure
int replace(Node * head, char old, char new) {

  // not yet implemented
  return 0;  // replace this stub

}

