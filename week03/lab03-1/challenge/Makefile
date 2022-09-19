CC=g++
CFLAGS=-std=c++14 -pedantic -Wall -Wextra -Werror -Wsign-conversion -Wconversion -Woverloaded-virtual -Wshadow -Wnull-dereference

default: SharedPointer

SharedPointer:
	$(CC) $(CFLAGS) SharedPointer.cpp -o SharedPointer.out

.PHONY: clean
clean:
	rm -f *.out