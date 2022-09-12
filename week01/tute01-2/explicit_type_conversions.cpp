#include <iostream>

int main() {
    int x{2};
    int y{5};
    double z{2.2};
    double result1{static_cast<double>(y / x)};
    double result2{static_cast<double>(y) / static_cast<double>(x)};
    double result3{static_cast<double>(static_cast<int>(z))};
    double result4 = static_cast<int>(z);
    // double result5{static_cast<int>(z)};

    std::cout << result1 << std::endl;
    std::cout << result2 << std::endl;
    std::cout << result3 << std::endl;
    std::cout << result4 << std::endl;
    // (void)result5;

    return 0;
}
