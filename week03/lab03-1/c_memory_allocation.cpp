#include <iostream>

int main() {
    int* int_ptr{(int*)malloc(sizeof(int))};
    *int_ptr = 3;
    std::cout << *int_ptr << std::endl;
    free(int_ptr);
}
