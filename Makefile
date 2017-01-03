all: Driver.o BallenDevLinkedList.o
	g++ -Wall Driver.o BallenDevLinkedList.o -o output.out

BallenDevLinkedList.o: BallenDevLinkedList.cpp
	g++ -Wall -c BallenDevLinkedList.cpp
	
Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~*.h.gch *#[

run:
	./output.out
