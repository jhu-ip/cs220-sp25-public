CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

main: main.o complex.o
	g++ -o main main.o complex.o
  
main.o: main.cpp complex.h
	g++ -c main.cpp $(CFLAGS)

complex.o: complex.cpp complex.h
	g++ -c complex.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm -f *.o main *~ *.gch
