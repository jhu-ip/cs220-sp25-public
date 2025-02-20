#include <stdio.h>
#include <limits.h>
#include <assert.h>

unsigned int magnitude(unsigned int value);

int main(void) {
  assert(542506478u == magnitude(542506478));
  assert(1835766762u == magnitude(-1835766762));
  assert(639157597u == magnitude(-639157597));
  assert(823316448u == magnitude(-823316448));
  assert(761420221u == magnitude(-761420221));
  assert(1233243675u == magnitude(-1233243675));
  assert(1496673002u == magnitude(1496673002));
  assert(1983295331u == magnitude(-1983295331));
  assert(568473921u == magnitude(-568473921));
  assert(2030626062u == magnitude(2030626062));

  printf("All tests passed! Nicely done!\n");

  return 0;
}

// TODO: implement the magnitude function without using the int data type!
unsigned int magnitude(unsigned int value) {

  return 0; // replace this stub
}
