#include <iostream>

int main() {
    int* int_ptr{new int{42}};
    std::cout << *int_ptr << std::endl;
    delete int_ptr;
}
