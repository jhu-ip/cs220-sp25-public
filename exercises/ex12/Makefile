# Sample Makefile

CC=gcc
CFLAGS=-g -std=c99 -pedantic -Wall -Wextra

# Links together files needed to create executable
main: sudoku.o sudokuHelpers.o
	$(CC) -o main sudoku.o sudokuHelpers.o

sudoku.o: sudoku.c sudokuHelpers.h
	$(CC) $(CFLAGS) -c sudoku.c

sudokuHelpers.o: sudokuHelpers.c sudokuHelpers.h
	$(CC) $(CFLAGS) -c sudokuHelpers.c

# Removes all object files and the executable named main,
# so we can start fresh
clean:
	rm -f *.o main
