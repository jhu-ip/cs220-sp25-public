#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "image_manip.h"
#include "ppm_io.h"


////////////////////////////////////////
// Definitions of the functions       //
// declared in image_manip.h go here! //
////////////////////////////////////////

/* Convert a RGB pixel to a single grayscale intensity;
* uses NTSC standard conversion
*/
unsigned char pixel_to_gray( Pixel p ) {
	return (unsigned char)( 0.3 * p.r + 0.59 * p.g + 0.11 * p.b );
}
