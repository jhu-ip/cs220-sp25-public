#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <assert.h>

char* strlist(const Node * head) {
    const Node * orig = head;
    char* str = malloc(length(head) * 2 * sizeof(char) + 1); // reserve space
    char* writepos = str;
    for (head = orig; head != NULL; head = head->next) {
        sprintf(writepos, "%c ", head->data);
        writepos += 2;
    }
    if (str == writepos)  // list was empty
      str[0] = '\0';
    else
      *(writepos-1) = '\0';    // overwrite the last space with NULL
    return str;
} 


int main() {
  
  Node * my_list = NULL;    // must initialize for good results!!

  for (char c = 'e'; c >= 'a'; c--) 
    add_front(&my_list, c);
  
  assert(length(my_list) == 5);
  char* str = strlist(my_list);
  assert(strcmp(str,"a b c d e") == 0);
  reverse_print(my_list);  // outputs e d c b a
  printf("\n");
  free(str);
    
  clear_list(&my_list);


  /******  This section primarily tests remove_after and remove_front. Uncomment after Part 2.

  // test remove_front, remove_after
  add_front(&my_list, 'A');
  add_after(my_list, 'M');
  add_after(my_list, 'H');
  add_after(my_list, 'c');
  add_after(my_list, 'S');
  add_after(my_list, 'b');
  
  str = strlist(my_list);
  assert(strcmp(str, "A b S c H M") == 0);
  free(str);
  assert(remove_front(&my_list) == 'A');
  str = strlist(my_list);
  assert(strcmp(str, "b S c H M") == 0);
  assert(length(my_list) == 5);
  free(str);

  assert(remove_after(my_list->next) == 'c');
  str = strlist(my_list);
  assert(strcmp(str, "b S H M") == 0);
  assert(length(my_list) == 4);
  free(str);
  clear_list(&my_list);
  assert(my_list == NULL);

   */



  /******  This section primarily tests remove_all. Uncomment after Part 4.

  // test remove_all
  for (char c = 'a'; c < 'j'; c++) {
    add_front(&my_list, c);
  }
  for (char c = 'i'; c >= 'c'; c--) {
    add_front(&my_list, c);
  }
  str = strlist(my_list);
  assert(strcmp(str, "c d e f g h i i h g f e d c b a") == 0);
  free(str);
  remove_all(&my_list, 'i');
  str = strlist(my_list);
  assert(strcmp(str, "c d e f g h h g f e d c b a") == 0);
  free(str);
  remove_all(&my_list, 'i');
  str = strlist(my_list);
  assert(strcmp(str, "c d e f g h h g f e d c b a") == 0);
  free(str);
  remove_all(&my_list, 'c');
  str = strlist(my_list);
  assert(strcmp(str, "d e f g h h g f e d b a") == 0);
  free(str);
  remove_all(&my_list, 'a');
  str = strlist(my_list);
  assert(strcmp(str, "d e f g h h g f e d b") == 0);
  free(str);
  clear_list(&my_list);
  assert(my_list == NULL);

   */


  /******  This section primarily tests insert. Uncomment after Part 6.

  // test insert
  for (char c = 'A'; c < 'F'; c++) {
    insert(&my_list, c);
  }
  str = strlist(my_list);
  assert(strcmp(str, "A B C D E") == 0);
  free(str);
  clear_list(&my_list);    
  for (char c = 'E'; c > 'A'; c--) {
    insert(&my_list, c);
  }
  str = strlist(my_list);
  assert(strcmp(str, "B C D E") == 0);
  free(str);
  insert(&my_list, 'J');
  insert(&my_list, 'D');
  insert(&my_list, 'A');
  str = strlist(my_list);
  assert(strcmp(str, "A B C D D E J") == 0);
  free(str);
  clear_list(&my_list);

   */


  /******  This section tests functions not required in the exercise.

  add_front(&my_list, 'S');
  add_tail(&my_list, 'N');
  add_front(&my_list, 'W');
  add_tail_rec(&my_list, 'H');
  str = strlist(my_list);
  assert(strcmp(str,"W S N H") == 0);
  free(str);

  // test remove, remove_rec
  assert(remove_char(&my_list, 'S') == 1);
  str = strlist(my_list);
  assert(strcmp(str, "W N H") == 0);
  free(str);
  assert(remove_char(&my_list, 'W') == 1);
  assert(remove_char(&my_list, 'Q') == 0);
  
  assert(remove_char_rec(&my_list, 'W') == 0);
  assert(remove_char_rec(&my_list, 'H') == 1);
  str = strlist(my_list);
  assert(strcmp(str,"N") == 0);
  free(str);

  // test find
  assert(find(my_list, 'N')->data == 'N');
  assert(find(my_list, 'W') == NULL);
  
  // test add_front, add_tail
  add_front(&my_list, 'A');
  add_tail(&my_list, 'Z');
  str = strlist(my_list);
  print_rec(my_list);  // outputs A N H Z
  printf("\n");
  assert(strcmp(str,"A N Z") == 0);
  free(str);

  // test replace
  assert(replace(my_list, 'Z', 'M') == 1);
  assert(replace(my_list, 'N', 'S') == 1);
  str = strlist(my_list);
  assert(strcmp(str,"A S M") == 0);
  print_rec(my_list);  // outputs A S M
  printf("\n");
  free(str);
  assert(replace(my_list, 'Z', 'P') == 0);

  // test add_after
  add_after(my_list, 'b');  // A b S M
  add_after(my_list->next->next, 'c'); // A b S c M
  str = strlist(my_list);
  assert(strcmp(str, "A b S c M") == 0);
  assert(length(my_list) == 5);
  free(str);
  */



  printf("all tests passed!\n");
  return 0;

}

