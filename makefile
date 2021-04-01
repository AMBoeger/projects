
# Variables are handy for making global changes to the makefile (e.g. -g flag)
CPP = g++
CPPFLAGS = -std=c++11 -Wall -Wpedantic -Wextra


# First target is always the default if you just run "make".
main: main.o hashTable.o
	$(CPP) $(CPPFLAGS) -g -o p5 main.cpp hashTable.cpp

clean: 
	rm *.o *p5 $(objects)
	
