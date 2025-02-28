/*****************************************************************************
 * Midterm Project - A program to generate a checkboard image in a PPM file
 * Note: for naming convention, we try to follow Google C++ style guide:
 *       https://google.github.io/styleguide/cppguide.html
 * It is not compulsory, but you are highly encouraged to follow a convention.
 *
 * Summary: This file implements a program to generate a checkboard image.
 *          It takes four optional arguments:
 *            The output filename (default: checkboard.ppm)
 *            The number of checkerboard columns (default: 7)
 *            The number of checkerboard rows (default: 5)
 *            The size of a checkerboard square (default: 50 pixels)
 *          The program will return 0 if the checkboard image is generated.
 *          Otherwise, it will return 1 for wrong usage, 2 for other errors.
 *
 * Note: this is for your reference.  Your shouldn't need to modify it.
 *****************************************************************************/
#include "ppm_io.h" // PPM I/O header
#include <stdlib.h> // c functions: atio


int main(int argc, char **argv) {
	// parsing command line arguments
  if (argc > 5) {
		printf("Usage: %s [output filename=checkerboard.ppm] [cols=7] [rows=5] [square size=50 pixels]\n", argv[0]);
		return 1; // return 1 for wrong usage
	}
	
  const char *filename = argc > 1 ? argv[1] : "checkerboard.ppm";
	const int num_cols = argc > 2 ? atoi(argv[2]) : 7;
  const int num_rows = argc > 3 ? atoi(argv[3]) : 5;
	const int square_size = argc > 4 ? atoi(argv[4]) : 50;

  // open a ppm file as binary to write
	FILE *fp = fopen(filename, "wb");
	if (!fp) {
		printf("Couldn't open output file: %s\n", filename);
		return 2; // return 2 for other errors
	}

  // allocate space for an Image
  Image *im = malloc(sizeof(Image));
  if (!im) {
    fprintf(stderr, "Uh oh. Image allocation failed!\n");
    return 2; // return 2 for other errors
  }
  
  // specify dimensions for the image
  im->rows = num_rows * square_size;
  im->cols = num_cols * square_size;
	
  // allocate space for array of Pixels
  Pixel *pix = malloc(sizeof(Pixel) * im->rows * im->cols);
  if (!pix) {
    fprintf(stderr, "Uh oh. Pixel array allocation failed!\n");
    free(im);
    fclose(fp);
    return 2; // return 2 for other errors
  }
  
  // let data field of Image point to the new array
  im->data = pix;
  
  // fill Pixel array by setting Pixels to a checkerboard pattern
  Pixel black = {0, 0, 0}, white = {255, 255, 255};
  for (int r = 0; r < num_rows; ++r) for (int c = 0; c < num_cols; ++c) {
    Pixel color = (r + c) % 2 == 0 ? white : black;
    for (int rr = 0; rr < square_size; ++rr) for (int cc = 0; cc < square_size; ++cc)
      im->data[(r * square_size + rr) * im->cols + c * square_size + cc] = color;
  }
  
  // write image to output file
  int num_pixels_written = write_ppm(fp, *im);
  fclose(fp);
  printf("Image created with %d pixels.\n", num_pixels_written);

  // clean up!
  free(im->data);  // releases the pixel array
  free(im);        // releases the image itself

	return 0;
}
