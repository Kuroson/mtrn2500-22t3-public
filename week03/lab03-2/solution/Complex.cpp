#include "Complex.hpp"
#include <cmath>
#include <iostream>
#include <type_traits>

Complex Complex::conjugate() const {
    return Complex(this->real_num_, -(this->imaginary_num_));
}

double Complex::modulus() const {
    return std::sqrt(std::pow(this->real_num_, 2) + std::pow(this->imaginary_num_, 2));
}

double Complex::argument() const {
    return std::atan2(this->imaginary_num_, this->real_num_);
}

Complex& Complex::operator=(Complex const& z) {
    // Copy then swap
    auto copy = Complex(z);
    std::swap(copy, *this);
    return *this;
}

Complex& Complex::operator=(Complex&& other) noexcept {
    // Swap
    std::swap(this->real_num_, other.real_num_);
    std::swap(this->imaginary_num_, other.imaginary_num_);
    // Clean up
    other.real_num_ = 0;
    other.imaginary_num_ = 0;
    return *this;
}

int main() {
    auto c1 = Complex(1, 2);
    std::cout << c1 << std::endl;
    auto const c2 = Complex(3, -4);
    std::cout << c2 << std::endl;
    return 0;
}