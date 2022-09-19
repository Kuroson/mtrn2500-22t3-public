#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3, 4};
    std::cout << "Address: " << &vec << " != " << vec.data() << std::endl;
    // Address: 0x7ffea4df2110 != 0x55e7531c8eb0
}