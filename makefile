# Default target
all: test

# Linking step
test: test3.o
	g++ -Wall -o test test3.o -fexceptions -lstdc++

# Compilation step
test3.o: test3.cpp ans3.h
	g++ -Wall -c test3.cpp -std=c++11 -fexceptions

# Clean up step
clean:
	rm -f test *.o

	
	
	



