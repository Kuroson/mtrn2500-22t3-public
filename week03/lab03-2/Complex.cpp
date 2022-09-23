#include "Complex.hpp"
#include <cmath>
#include <iostream>

int main() {
    auto c1 = Complex(1, 2);
    std::cout << c1 << std::endl;
    auto const c2 = Complex(3, -4);
    std::cout << c2 << std::endl;
    return 0;
}