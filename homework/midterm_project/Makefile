# Midterm Project Makefile

CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra

# Links together files needed to create executable
project: project.o ppm_io.o image_manip.o
	$(CC) project.o ppm_io.o image_manip.o -o project -lm

# Links together files needed to create the image comparison executable
img_cmp : img_cmp.o ppm_io.o
	$(CC) -o $@ img_cmp.o ppm_io.o

# Links together files needed to create the checkerboard executable
checkerboard : checkerboard.o ppm_io.o
	$(CC) -o $@ checkerboard.o ppm_io.o

# Compile the project source code
project.o: project.c ppm_io.h image_manip.h
	$(CC) $(CFLAGS) -c project.c -g

# Compile checkerboard source code
checkerboard.o : checkerboard.c ppm_io.c
	$(CC) $(CFLAGS) -c checkerboard.c ppm_io.c -g

# Compile img_cmp source code
img_cmp.o : img_cmp.c ppm_io.c
	$(CC) $(CFLAGS) -c img_cmp.c -g

# Compile the imgage manipulation source code
image_manip.o: image_manip.c image_manip.h ppm_io.h
	$(CC) $(CFLAGS) -c image_manip.c -g

# Compile the ppm i/o source code
ppm_io.o: ppm_io.c ppm_io.h
	$(CC) $(CFLAGS) -c ppm_io.c -g


# Removes all object files and the executable named project,
# so we can start fresh
clean:
	rm -f *.o project img_cmp checkerboard
