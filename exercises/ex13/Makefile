CC=gcc
CFLAGS=-g -std=c99 -pedantic -Wall -Wextra

# Links together files needed to create executable
main: soccer.o main.o
	$(CC) -o main main.o soccer.o

# Compiles main.c to create main.o
main.o: main.c soccer.h
	$(CC) $(CFLAGS) -c main.c -g

# Compiles soccer.c to create read_line.o
soccer.o: soccer.c soccer.h
	$(CC) $(CFLAGS) -c soccer.c -g

# Removes all object files and the executable named main,
# so we can start fresh
clean:
	rm -f *.o main *~
