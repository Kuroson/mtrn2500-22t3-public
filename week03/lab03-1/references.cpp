#include <iostream>

int main() {
    int a{3};
    int& b{a};
    std::cout << a << " " << b << std::endl;
    a = 4;
    std::cout << a << " " << b << std::endl;
}
