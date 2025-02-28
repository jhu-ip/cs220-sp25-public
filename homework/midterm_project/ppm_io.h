#ifndef PPM_IO_H
#define PPM_IO_H

#include <stdio.h>

/* struct to store a point */
typedef struct {
  int x;
  int y;
} Point;

/* struct to store an RGB pixel, one byte per channel */
typedef struct {
  unsigned char r;
  unsigned char g;
  unsigned char b;
} Pixel;

/* struct to store an entire image
 * pixels are linearized in row-major order, with the first block of pixels corresponding to the first row, then the second, etc.
 */
typedef struct {
  Pixel *data;
  int rows;
  int cols;
} Image;

/* read PPM formatted image from a file (assumes fp != NULL) */
Image read_ppm( FILE * fp );

/* write PPM formatted image to a file (assumes fp != NULL) */
int write_ppm( FILE * fp , const Image img );

/* utility function to free inner and outer pointers,
 * and set to null */
void free_image( Image * im );

/* allocate a new image of the specified size;
 * doesn't initialize pixel values */
Image make_image( int rows , int cols );

/* output dimensions of the image to stdout */
void output_dims( const Image im );

#endif
