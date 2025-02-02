# Sample Makefile

CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra

# Links together files needed to create executable
main: main_file.o functions.o
	$(CC) -o main main_file.o functions.o

# Compiles mainFile.c to create mainFile.o
# Note that we list functions.h here as a file that
# main_file.c depends on, since main_file.c #includes it
main_file.o: main_file.c functions.h
	$(CC) $(CFLAGS) -c main_file.c

# Compiles functions.c to create functions.o
# Note that we list functions.h here as a file that
# functions.c depends on, since functions.c #includes it
functions.o: functions.c functions.h
	$(CC) $(CFLAGS) -c functions.c

# Removes all object files and the executable named main,
# so we can start fresh
clean:
	rm -f *.o main
