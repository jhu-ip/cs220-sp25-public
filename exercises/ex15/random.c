#include <stdio.h>
#include <stdlib.h> // for rand
#include <string.h> // for memset

// function prototypes
void print_hist(int counts[], int max);
void set_seed(int seed);
int gen_uniform(int max);
int normal_rand(int max);

int main(void) {

  int seed, max_range;
  printf("Enter a seed number and max range <= 30: ");
  if (scanf(" %d %d", &seed, &max_range) != 2) { // read a seed number
    printf("Could not read the seed number and max range - quitting\n");
    return 1;
  }
  if (max_range > 30) {
    printf("invalid range max - quitting\n");
    return 1;
  }

  int hist[max_range];

  // clear hist array for experiment 1
  memset(hist, 0, sizeof(hist));

  // Experiment 1: generate 500 pseudo-random numbers in the range
  // 0..max_range-1 by repeatedly calling the gen_uniform() function
  // and incrementing the element of the hist array whose index is
  // equal to the returned value. 

  // TODO (3): generate 500 uniformly distributed pseudo-random values


  printf("Uniform distribution:\n");
  print_hist(hist, max_range);

  // clear hist array for experiment 2
  memset(hist, 0, sizeof(hist));

  // Experiment 2: generate 500 pseudo-random numbers in the range
  // 0..max_range-1 by repeatedly calling the normal_rand() function
  // and incrementing the element of the hist array whose index is
  // equal to the returned value. 

  // TODO (5): generate 500 normally distributed pseudo-random values

  
  printf("Normal distribution:\n");
  print_hist(hist, max_range);

  return 0;
}

const char *BAR = "********************************************************************************************************************************************************************************************************************************************************************************************************************************";

void print_hist(int counts[], int max) {
  for (int i = 0; i < max; i++) {
    printf("%2d: %.*s\n", i, counts[i], BAR);
  }
}

// This function sets the seed of the random generation by calling srand()
void set_seed(int seed) {
  // TODO (1): WRITE IMPLEMENTATION
}

// This function generates a random integer between 0 (inclusive)
// and a maximum value (exclusive) using a uniform distribution
// Example gen_uniform(50) should return an integer in range [0, 50)
int gen_uniform(int max_num) {
  // TODO (2): WRITE IMPLEMENTATION
  return -1;  // replace this stub
}

// This function returns a pseudo-random integer in the range 0..max_num-1 (inclusive),
// but in a normal ("bell shaped") distribution.
// Hint: the sum of multiple uniformly distributed random numbers will fall in
// a normal distribution. So, for example, you could generate n values between
// 0 and (max_num / n + 1) and add them together to get a normally distributed value
// between 0..max_num, just being careful about edge cases.
int normal_rand(int max_num) {
  // TODO (4): WRITE IMPLEMENTATION
  return -1;  // replace this stub
}
