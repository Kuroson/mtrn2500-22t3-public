#include "SharedPointer.hpp"
#include <iostream>
#include <utility>

std::unordered_map<int*, long> SharedPointer::reference_count_ = std::unordered_map<int*, long>();

int* SharedPointer::get() {
    return this->pointer_;
}

int const* SharedPointer::get() const {
    return this->pointer_;
}

int& SharedPointer::operator*() {
    return *this->pointer_;
}

long SharedPointer::use_count() const {
    // There is the assumption that `pointer_` is in the map
    return this->reference_count_.find(this->pointer_)->second;
}

int const& SharedPointer::operator*() const {
    return *this->pointer_;
}

int main() {
    auto* ptr = new int{42}; // Malloc the memory for an integer with a value of 42
    auto sp_1 = SharedPointer(ptr); // Create an instance
    std::cout << "count: " << sp_1.use_count() << std::endl;
    auto sp_2 = SharedPointer{ptr};
    std::cout << "count: " << sp_1.use_count() << std::endl;

    {
        auto const sp_3 = SharedPointer{ptr};
        std::cout << "count: " << sp_1.use_count() << std::endl;
    } // sp_3 gets deleted

    std::cout << "count: " << sp_1.use_count() << std::endl;

    auto const sp_4 = SharedPointer{ptr};
    auto sp_4_ptr = sp_4.get(); // Gets me the pointer as a const

    std::cout << sp_4_ptr << " vs " << ptr << std::endl;

    auto& test2 = *sp_1; // Gets me a reference of the integer
    std::cout << test2 << std::endl;
    test2 = 100; // Change the value using the reference
    std::cout << *(sp_1.get()) << std::endl; // Get the address of the integer and deference to
                                             // print value

    auto const& test3 = *sp_4; // Get a const reference of integer
    std::cout << test3 << std::endl;
}