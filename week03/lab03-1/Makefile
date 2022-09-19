CC=g++
CFLAGS=-std=c++14 -pedantic -Wall -Wextra -Werror -Wsign-conversion -Wconversion -Woverloaded-virtual -Wshadow -Wnull-dereference

default: array_first_memory vector_first_memory vector_contigous c_memory_allocation cpp_memory_allocation unique_ptr shared_ptr weak_ptr convert_to_smart_pointers convert_to_smart_pinters_2 pass_by_references loops

array_first_memory:
	$(CC) $(CFLAGS) array_first_memory.cpp -o array_first_memory.out

array_contigous:
	$(CC) $(CFLAGS) array_contigous.cpp -o array_contigous.out

vector_first_memory:
	$(CC) $(CFLAGS) vector_first_memory.cpp -o vector_first_memory.out

vector_contigous:
	$(CC) $(CFLAGS) vector_contigous.cpp -o vector_contigous.out

c_memory_allocation:
	$(CC) $(CFLAGS) c_memory_allocation.cpp -o c_memory_allocation.out

cpp_memory_allocation:
	$(CC) $(CFLAGS) cpp_memory_allocation.cpp -o cpp_memory_allocation.out

unique_ptr:
	$(CC) $(CFLAGS) unique_ptr.cpp -o unique_ptr.out

shared_ptr:
	$(CC) $(CFLAGS) shared_ptr.cpp -o shared_ptr.out

weak_ptr:
	$(CC) $(CFLAGS) weak_ptr.cpp -o weak_ptr.out

convert_to_smart_pointers:
	$(CC) $(CFLAGS) convert_to_smart_pointers.cpp -o convert_to_smart_pointers.out

convert_to_smart_pinters_2:
	$(CC) $(CFLAGS) convert_to_smart_pointers_2.cpp -o convert_to_smart_pointers_2.out

references:
	$(CC) $(CFLAGS) references.cpp -o references.out

pass_by_references:
	$(CC) $(CFLAGS) pass_by_references.cpp -o pass_by_references.out

loops:
	$(CC) $(CFLAGS) loops.cpp -o loops.out

.PHONY: clean
clean:
	rm -f *.out