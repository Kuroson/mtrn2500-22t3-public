#include <iostream>

int main() {
    int a{2};
    char b{'b'};
    double c{a * 0.1};
    int d{c};

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    std::cout << d << std::endl;
}
