#include <stdio.h>



int main() {
  float a = 5, b = 8;
  printf("%f divided by %f is %f\n", a, b, div(a, b));

  // Part 2 - to test mult
  //printf("%f x %f is %f (expected 40)\n", a, b, mult(a, b));

  // Part 2 - to test fac
  //printf("factorial of -4 is %ld (expected 0)\n", fac(-4));
  //printf("factorial of 10 is %ld (expected 3628800)\n", fac(10));

  // Part 3 - to test bsearch
  //float myray[] = {3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.0, 10, 15, 20, 25, 100};
  //int capacity = sizeof(myray) / sizeof(myray[0]);
  //int where = bsearch(myray, 0, capacity-1, 5.6);
  //printf("binary search of 5.6 found at index: %d\n", where);
  //where = bsearch(myray, 0, capacity-1, 30);
  //printf("binary search of 30 found at index: %d\n", where);

  // Part 3 - to test bsearch2
  //float results[12] = {0};
  //where = bsearch2(myray, 0, capacity-1, 10, results, 0);
  //printf("binary search of 10 found at index: %d\n", where);
  //printf("results array is: " );
  //for (int i = 0; i < capacity; i++) {
  //  printf("%.1f ", results[i]);
  //}
  //printf("\n");

  return 0;
}

float div(float a, float b) {
  return a / b;
}

