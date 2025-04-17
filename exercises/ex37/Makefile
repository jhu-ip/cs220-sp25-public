CONSERVATIVE_FLAGS = -std=c++11 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

main1: main1.cpp MyList.h MyList.inc MyNode.h 
	g++ -o main1 main1.cpp $(CFLAGS)

main2: main2.cpp MyList.h MyList.inc MyNode.h 
	g++ -o main2 main2.cpp $(CFLAGS)

main3: main3.cpp MyList.h MyList.inc MyNode.h 
	g++ -o main3 main3.cpp $(CFLAGS)

main4: main4.cpp MyList.h MyList.inc MyNode.h 
	g++ -o main4 main4.cpp $(CFLAGS)

clean:
	rm -f *.o main1 main2 main3 main4