#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"


int main() {

  // create nodes
  Node * n1 = create_node('A');
  Node * n2 = create_node('C');
  Node * n3 = create_node('E');
  Node * n4 = create_node('G');

  //link nodes
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;

  print(n1);    // prints A C E G
  printf("\n"); 

  // MINI EXERCISE PART 1: uncomment following when you have
  // finished implementing the length function in list.c
  // don't forget to add function declaration in the header

  // assert(length(n1) == 4);
  
  // MINI EXERCISE PART 2: uncomment followings when you have
  // finished implementing the add_after function in list.c
  // don't forget to add function declaration in the header
  
  // add_after (n1, 'B');
  // add_after (n2, 'D');
  // add_after (n3, 'F');
  // assert(length(n1) == 7); // there must be 7 nodes now
  // print(n1); // should now print A B C D E F G
  // printf("\n");

  // MINI EXERCISE PART 3: uncomment following when you have
  // finished implementing the reverse_print function in list.c
  // don't forget to add function declaration in the header
  
  // reverse_print(n1); // should now print G F E D C B A
  // printf("\n");
  
  // don't forget to free the memory
  Node * prev;
  Node * cur = n1;

  while (cur) {
    prev = cur;
    cur = cur->next;
    free(prev);
  }
}
