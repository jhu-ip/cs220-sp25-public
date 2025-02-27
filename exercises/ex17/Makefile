CC = gcc
CFLAGS = -std=c99 -pedantic -Wall -Wextra -g

# create executable
test: list_test.o list.o
	$(CC) list_test.o list.o -o test

# create object file for testing linked list functions
list_test.o: list_test.c list.h
	$(CC) $(CFLAGS) -c list_test.c

# create object file for linked list functions
list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

# clean up
clean:
	rm -f *~ *.o test
