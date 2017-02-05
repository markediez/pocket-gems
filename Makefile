all: Data.o Node.o LinkedList.o
	g++ -Wall -std=c++11 challenge.cpp Data.o Node.o LinkedList.o -o program.out

LinkedList.o: LinkedList.h LinkedList.cpp Data.o Node.o
	g++ -Wall -std=c++11 -c LinkedList.cpp

Node.o: Node.h Node.cpp Data.o
	g++ -Wall -std=c++11 -c Node.cpp

Data.o: Data.h Data.cpp
	g++ -Wall -std=c++11 -c Data.cpp

clean:
	rm -rf *.o
	rm -rf *.out
