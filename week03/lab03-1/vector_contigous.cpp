#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4};
    std::cout << vec.capacity() << std::endl;
    for (std::size_t i{0}; i < vec.size(); i++) {
        std::cout << i << ": " << vec.data() + i << std::endl;
    }
    // 0: 0x55ba8abe3eb0
    // 1: 0x55ba8abe3eb4
    // 2: 0x55ba8abe3eb8
    // 3: 0x55ba8abe3ebc
}