#include <iostream>
#include <memory>

int main() {
    auto x = std::make_shared<int>(5);
    auto y = x; // Using copy constructor
    std::cout << "use count: " << x.use_count() << "\n"; // 2
    std::cout << "value: " << *x << "\n"; // 5
    x.reset(); // Memory still exists, due to y.
    std::cout << "use count: " << y.use_count() << "\n"; // 1
    std::cout << "value: " << *y << "\n"; // 5
    y.reset(); // Deletes the memory, since
    // no one else owns the memory
    std::cout << "use count: " << x.use_count() << "\n"; // 0
    // std::cout << "value: " << *y << "\n";
}