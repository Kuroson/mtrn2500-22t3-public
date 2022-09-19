#include <iostream>

void foo(int& arg1, int arg2) {
    arg1++;
    arg2++;
}

int main() {
    int a{3};
    int& b{a};
    int c{4};
    std::cout << a << " " << b << " " << c << std::endl;
    foo(a, b);
    std::cout << a << " " << b << " " << c << std::endl;
    foo(c, a);
    std::cout << a << " " << b << " " << c << std::endl;
}
