#include "Complex.hpp"
#include <cmath>
#include <iostream>

int main() {
    auto c1 = Complex(1, 2);
    std::cout << c1 << std::endl;
    auto const c2 = Complex(3, -4);
    std::cout << c2 << std::endl;
    auto c3 = c2; // Copy constructor
    c3 = c1; // copy assignment
    return 0;
}