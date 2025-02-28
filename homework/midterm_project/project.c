//project.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ppm_io.h"
#include "image_manip.h"

// Return (exit) codes
#define RC_SUCCESS            0
#define RC_MISSING_FILENAME   1
#define RC_OPEN_FAILED        2
#define RC_INVALID_PPM        3
#define RC_INVALID_OPERATION  4
#define RC_INVALID_OP_ARGS    5
#define RC_OP_ARGS_RANGE_ERR  6
#define RC_WRITE_FAILED       7
#define RC_UNSPECIFIED_ERR    8

void print_usage(void);

int main (int argc, char* argv[]) {
  // Complete the implementation of main
  return RC_SUCCESS; // Replace Me!
}

void print_usage(void) {
  printf("USAGE: ./project <input-image> <output-image> <command-name> <command-args>\n");
  printf("SUPPORTED COMMANDS:\n");
  printf("   invert\n" );
  printf("   zoom-out\n" );
  printf("   binarize <threshold>\n" );
  printf("   pointilism\n" );
  printf("   blur <sigma>\n" );
  printf("   crop <top left (x,y)> <bottom right (x,y)>\n" );
}


