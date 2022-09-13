CC=g++
CFLAGS=-std=c++14 -pedantic -Wall -Wextra -Werror -Wsign-conversion -Wconversion -Woverloaded-virtual -Wshadow -Wnull-dereference

default: hello_world fizz_buzz function_overloading explicit_type_conversions auto leap_year sum_prime input_output

hello_world:
	$(CC) $(CFLAGS) hello_world.cpp -o hello_world.out

fizz_buzz:
	$(CC) $(CFLAGS) fizz_buzz.cpp -o fizz_buzz.out

function_overloading:
	$(CC) $(CFLAGS) function_overloading.cpp -o function_overloading.out

explicit_type_conversions:
	$(CC) $(CFLAGS) explicit_type_conversions.cpp -o explicit_type_conversions.out

auto:
	$(CC) $(CFLAGS) auto.cpp -o auto.out

leap_year:
	$(CC) $(CFLAGS) leap_year.cpp -o leap_year.out

sum_prime:
	$(CC) $(CFLAGS) sum_prime.cpp -o sum_prime.out

input_output:
	$(CC) $(CFLAGS) input_output.cpp -o input_output.out

.PHONY: clean
clean:
	rm -f *.out