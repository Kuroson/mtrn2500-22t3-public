#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <cmath>
#include <iostream>
#include <ostream>
#include <utility>

/**
 * @brief Class that represents a complex number
 */
class Complex {
  public:
    /**
     * @brief Default constructor.
     * Default initialises all members
     */
    Complex() = default;

    /**
     * @brief Construct a new Complex object with a real `real` component
     *
     * @param real real component
     */
    Complex(double const& real)
    : Complex(real, 0) {}
    // : real_num_{real}
    // , imaginary_num_{0} {}

    /**
     * @brief Construct a new Complex object with a real `real` and imaginary `imaginary` component
     *
     * @param real real component
     * @param imaginary imaginary component
     */
    Complex(double const& real, double const& imaginary)
    : real_num_{real}
    , imaginary_num_{imaginary} {}

    /**
     * @brief Copy constructor.
     * Creates a copy based on `other` value
     *
     * @param other object to copy
     */
    Complex(Complex const& other)
    : Complex(other.real_num_, other.imaginary_num_) {
        std::cout << "Copy constructor" << std::endl;
    }
    // : real_num_{other.real_num_}
    // , imaginary_num_{other.imaginary_num_} {}

    /**
     * @brief Move constructor. Moves the value of `other` to this object
     * and then sets `other` to default values
     *
     * @param other object to move and set to default values
     */
    Complex(Complex&& other)
    : real_num_{std::move(other.real_num_)}
    , imaginary_num_{std::move(other.imaginary_num_)} // I have moved the data inside of other
    {
        // Now i have to invalidate the data inside of `other`
        other.real_num_ = 0;
        other.imaginary_num_ = 0;
    }

    /**
     * @brief Destroy the Complex object.
     * Default destructor as no dynamic memory is used
     */
    ~Complex() {
        std::cout << "Complex was destroyed" << std::endl;
    }

    /**
     * @brief Returns the conjugate of the complex number
     *
     * @return Complex
     */
    Complex conjugate() const {
        return Complex(real_num_, -imaginary_num_);
    }

    /**
     * @brief Returns the modulus of the complex number
     *
     * @return double
     */
    double modulus() const {
        return std::sqrt(real_num_ * real_num_ + imaginary_num_ * imaginary_num_);
    }

    /**
     * @brief Returns the argument of the complex number
     *
     * @return double
     */
    double argument() const;

    /**
     * @brief Copy assignment overload. Copies the value of `other` to this object
     *
     * @param other object to copy
     * @return Complex&
     */
    Complex& operator=(Complex const& other) {
        std::cout << "Copy assignment" << std::endl;
        // Copy then swap
        auto copy = Complex(other); // This creates a copy
        std::swap(copy, *this); // This swaps the data inside of copy and *this
        return *this;
    }

    /**
     * @brief Move assignment overload. Moves the value of `other` to this object
     * and sets `other` to default values
     *
     * @param other object to move
     * @return Complex&
     */
    Complex& operator=(Complex&& other) noexcept {
        // Swap
        std::swap(this->real_num_, other.real_num_);
        std::swap(this->imaginary_num_, other.imaginary_num_);
        // Clean up, invalidation
        other.imaginary_num_ = 0;
        other.real_num_ = 0;
        return *this;
    }

    /**
     * @brief Returns the conjugate of `z`
     *
     * @param z
     * @return Complex
     */
    static Complex make_conjugate(Complex const& z) {
        return z.conjugate();
    }

    /**
     * @brief Returns the addition of two complex numbers
     *
     * @param lhs
     * @param rhs
     * @return Complex
     */
    friend Complex operator+(Complex const& lhs, Complex const& rhs) {
        return Complex(lhs.real_num_ + rhs.real_num_, lhs.imaginary_num_ + rhs.imaginary_num_);
    }

    /**
     * @brief Returns the subtraction of two complex numbers
     *
     * @param lhs
     * @param rhs
     * @return Complex
     */
    friend Complex operator-(Complex const& lhs, Complex const& rhs) {
        return Complex(lhs.real_num_ - rhs.real_num_, lhs.imaginary_num_ - rhs.imaginary_num_);
    }

    /**
     * @brief Returns the multiplication of two complex numbers
     *
     * @param lhs
     * @param rhs
     * @return Complex
     */
    friend Complex operator*(Complex const& lhs, Complex const& rhs);

    /**
     * @brief Checks if `lhs` and `rhs` are the same complex number
     *
     * @param lhs
     * @param rhs
     * @return true
     * @return false
     */
    friend bool operator==(Complex const& lhs, Complex const& rhs) {
        // real_num_ => double
        // Doing comparisons
        // We really should epslion testing
        return lhs.real_num_ == rhs.real_num_ && lhs.imaginary_num_ == rhs.imaginary_num_;
    }

    /**
     * @brief Checks if `lhs` and `rhs` are not the same complex number
     *
     * @param lhs
     * @param rhs
     * @return true
     * @return false
     */
    friend bool operator!=(Complex const& lhs, Complex const& rhs) {
        return !(lhs == rhs);
    }

    /**
     * @brief Writes the complex number in the form of a+bi to the output stream
     *
     * @param os output stream to write to
     * @param z complex number to write
     * @return std::ostream&
     */
    friend std::ostream& operator<<(std::ostream& os, Complex const& z) {
        os << z.real_num_ << " + " << z.imaginary_num_ << "i";
        return os;
    }

  private:
    double real_num_;
    double imaginary_num_;
};

#endif // COMPLEX_HPP