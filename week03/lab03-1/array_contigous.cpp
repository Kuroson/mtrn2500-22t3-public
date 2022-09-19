#include <array>
#include <iostream>

int main() {
    std::array<int, 4> arr{1, 2, 3, 4};
    for (std::size_t i{0}; i < arr.size(); i++) {
        std::cout << i << ": " << &arr.at(i) << std::endl;
    }
    // Actual values differs from each run
    // 0: 0x7ffdc616b400
    // 1: 0x7ffdc616b404
    // 2: 0x7ffdc616b408
    // 3: 0x7ffdc616b40c
}