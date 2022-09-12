CC=g++
CFLAGS=-std=c++14 -pedantic -Wall -Wextra -Wsign-conversion -Wconversion -Woverloaded-virtual -Wshadow -Wnull-dereference

default: hello_world main variables control_flow number_loop

hello_world:
	$(CC) $(CFLAGS) hello_world.cpp -o hello_world.out

main:
	$(CC) $(CFLAGS) main.cpp -o main.out

variables:
	$(CC) $(CFLAGS) variables.cpp -o variables.out

control_flow:
	$(CC) $(CFLAGS) control_flow.cpp -o control_flow.out

number_loop:
	$(CC) $(CFLAGS) number_loop.cpp -o number_loop.out

.PHONY: clean
clean:
	rm -f *.out