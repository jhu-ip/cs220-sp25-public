#include <stdio.h>
#include <math.h>
#include <assert.h>

// stdio.h for input & output functions
// math.h for pow, exp  (compile with -lm option)
// assert.h for assert

// This is a helper function; main function is below.
// This function calculates the result of compounding
// a year's worth of interest on a principle, based on
// the interest rate and how often it is compounded.
// See formulas and check your results using
// https://www.calculatorsoup.com/calculators/financial/compound-interest-calculator.php

float compound_interest(float p, float r, int n) {
  // p is principal
  // r is annual rate
  // n is number of compoundings annually

  // n=1 means annual
  // n=12 means monthly
  // n=0 indicates continuous compounding

  assert(n >= 0);

  // Hint: use the pow(...) and exp(...) functions, declared in
  // math.h, for calculations below

  if (n > 0) {
    // TODO: Compute and return compound interest
  } else {
    // TODO: Compute and return continuously compounded interest
  }
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    printf("Error: must include input file name\n");
    return 1;
  }
  char * filename = argv[1];  // (copy) pointer to the filename

  // TODO: Open filename for reading, handle errors

  // TODO: Open output.txt file for writing, handle errors


  int line = 1;
  float p = 0.0;
  float r = 0.0;
  int parse;  // save return value of parsing attempt below

  // TODO: parse p, r from file, proceed with loop if successful
  while (parse == 2) {
    
    line++;

    // If we're testing whether the user gave us sensible input,
    // we use `if` and print relevant error messages as usual

    if (p < 0.0) {
      printf("Error: principal less than 0 on line %d: %f\n", line, p);
      return 1;
    }
    if (r <= 0.0) {
      printf("Error: rate is <= 0 on line %d: %f\n", line, r);
      return 1;
    }

    // assert(...) statements are "sanity checks"; if false,
    // implies something is wrong with our program

    float ci_annual = compound_interest(p, r, 1);
    // compounding should only increase principal
    assert(ci_annual >= p);

    float ci_monthly = compound_interest(p, r, 12);
    // monthly should increase more than annual
    assert(ci_monthly >= ci_annual);

    float ci_cont = compound_interest(p, r, 0);
    // continuous should increase more than monthly
    assert(ci_cont >= ci_monthly);

    // TODO: print the three answers to the output file
    //       using "%0.2f %0.2f %0.2f\n" as the fprintf
    //       format string.  Print ci_annual, ci_monthly
    //       then ci_cont.
  }

  // TODO: return non-0 if error prevented us from completing

  // TODO: use ferror to check both input and output for errors

  // TODO: close both input and output using fclose



  return 0;
}
