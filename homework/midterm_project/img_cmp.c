#include <stdio.h>
#include <stdlib.h>
#include "ppm_io.h"

int check_color(unsigned char c1, unsigned c2, int max_delta) {
	int diff = abs((int)c1 - (int)c2);
	return diff <= max_delta;
}

int check_pixels(Pixel p1, Pixel p2, int max_delta) {
	return check_color(p1.r, p2.r, max_delta)
		&& check_color(p1.g, p2.g, max_delta)
		&& check_color(p1.b, p2.b, max_delta);
}

int main(int argc, char **argv) {
	if (argc != 4) {
		printf("Usage: %s <max delta> <file1> <file2>\n", argv[0]);
		return 1;
	}

	int max_delta = atoi(argv[1]);
	const char *file1 = argv[2];
	const char *file2 = argv[3];

	FILE *fp1 = fopen(file1, "rb");
	if (!fp1) {
		printf("Couldn't open %s\n", file1);
		return 1;
	}
	FILE *fp2 = fopen(file2, "rb");
	if (!fp2) {
		fclose(fp1);
		printf("Couldn't open %s\n", file2);
		return 1;
	}

	Image im1 = read_ppm(fp1);
	if (!im1.data) {
		fclose(fp1);
		fclose(fp2);
		printf("%s is not a valid PPM file\n", file1);
		return 1;
	}
	Image im2 = read_ppm(fp2);
	if (!im2.data) {
		free_image(&im1);
		fclose(fp1);
		fclose(fp2);
		printf("%s is not a valid PPM file\n", file2);
		return 1;
	}

	fclose(fp1);
	fclose(fp2);

	if (im1.cols != im2.cols || im1.rows != im2.rows) {
		free_image(&im1);
		free_image(&im2);
		printf("Image dimensions differ\n");
		return 1;
	}

	// Count the number of pixels containing color component values
	// that differ than more than the max delta
	int mismatched = 0;
	int num_pixels = im1.cols * im1.rows;
	for (int i = 0; i < num_pixels; i++) {
		Pixel p1 = im1.data[i];
		Pixel p2 = im2.data[i];
		if (!check_pixels(p1, p2, max_delta)) {
			mismatched++;
		}
	}

	printf("Number of mismatched pixels: %d\n", mismatched);

	free_image(&im1);
	free_image(&im2);

	// Return 1 (unsuccessful) if any pixels had color component values
	// that differed by more than the max delta.
	return (mismatched == 0) ? 0 : 1;
}
