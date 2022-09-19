#include <iostream>
#include <memory>

int main() {
    auto x = std::make_shared<int>(1);
    auto wp = std::weak_ptr<int>(x); // x owns the memory
    auto y = wp.lock(); // Creates a shared_ptr
    if (y != nullptr) { // x and y own the memory
        // Do something with y
        std::cout << "Attempt 1: " << *y << '\n';
    }
}