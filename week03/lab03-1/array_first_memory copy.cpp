#include <array>
#include <iostream>

int main() {
    std::array<int, 4> arr{1, 2, 3, 4};
    std::cout << "Address: " << &arr << " == " << arr.data() << std::endl;
    // Address: 0x7ffcf7562b70 == 0x7ffcf7562b70
}