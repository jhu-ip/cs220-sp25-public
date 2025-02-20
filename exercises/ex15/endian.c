#include <stdio.h>

int main(void) {
  // print sizes of some integer data types
  printf("sizeof(char) = %zd\n", sizeof(char));
  printf("sizeof(short) = %zd\n", sizeof(short));
  printf("sizeof(int) = %zd\n", sizeof(int));
  printf("sizeof(long) = %zd\n", sizeof(long));
  printf("sizeof(unsigned char) = %zd\n", sizeof(unsigned char));
  printf("sizeof(unsigned short) = %zd\n", sizeof(unsigned short));
  printf("sizeof(unsigned int) = %zd\n", sizeof(unsigned int));
  printf("sizeof(unsigned long) = %zd\n", sizeof(unsigned long));


  // uncomment this part, then use gdb to determine whether
  // the value in the "val" variable is stored as big endian
  // or little endian
  //unsigned int val = 950238851u;

  //unsigned int *p = &val;
  //printf("%u\n", *p);


  return 0;
}
