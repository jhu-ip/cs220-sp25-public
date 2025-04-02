CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

main1: main1.o
	g++ -o main1 main1.o

main1.o: main1.cpp my_set.h my_set.inc my_node.h
	g++ -c main1.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o main?  *~
