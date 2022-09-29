CC=g++
CFLAGS=-std=c++14 -pedantic -Wall -Wextra -Werror -Wsign-conversion -Wconversion -Woverloaded-virtual -Wshadow -Wnull-dereference

default: Complex SharedPointer Robot
 
Complex:
	$(CC) $(CFLAGS) Complex.cpp -o Complex.out

SharedPointer:
	$(CC) $(CFLAGS) SharedPointer.cpp -o SharedPointer.out

Robot:
	$(CC) $(CFLAGS) Robot.cpp -o Robot.out

.PHONY: clean
clean:
	rm -f *.out