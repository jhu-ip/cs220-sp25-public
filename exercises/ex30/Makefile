CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

main1: main1.o int_set.o
	g++ -o main1 main1.o int_set.o

main1.o: main1.cpp int_set.h
	g++ -c main1.cpp $(CFLAGS)

int_set.o: int_set.cpp int_set.h int_node.h
	g++ -c int_set.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o main?  *~
