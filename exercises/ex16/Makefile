CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -g

# create executable
main: main.o list.o
	$(CC) main.o list.o -o main

# create object file for testing linked list functions
main.o: main.c list.h
	$(CC) $(CFLAGS) -c main.c

# create object file for linked list functions
list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

# clean up
clean:
	rm -f *~ *.o main
