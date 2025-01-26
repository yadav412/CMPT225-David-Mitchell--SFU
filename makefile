all: test

test: test.o
	g++ -Wall -o test test.o  

test.o: AlistTest.cpp Alist.h 
	g++ -Wall -o test.o -c AlistTest.cpp 

clean:
	rm -f test *.o

