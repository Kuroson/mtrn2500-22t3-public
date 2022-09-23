#ifndef COMPLEX_HPP
#define COMPLEX_HPP

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
    : Complex(real, double{}) {}

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
     * @brief Copy constructor. Creates a copy based on `other` value
     *
     * @param other object to copy
     */
    Complex(Complex const& other)
    : Complex(other.real_num_, other.imaginary_num_) {}

    /**
     * @brief Move constructor. Moves the value of `other` to this object
     * and then sets `other` to default values
     *
     * @param other object to move and set to default values
     */
    Complex(Complex&& other) noexcept
    : real_num_{std::move(other.real_num_)}
    , imaginary_num_{std::move(other.imaginary_num_)} {
        // Invalidate/reset members to default values
        other.real_num_ = 0;
        other.imaginary_num_ = 0;
    }

    /**
     * @brief Destroy the Complex object.
     * Default destructor as no dynamic memory is used
     */
    ~Complex() = default;

    /**
     * @brief Returns the conjugate of the complex number
     *
     * @return Complex
     */
    Complex conjugate() const;

    /**
     * @brief Returns the modulus of the complex number
     *
     * @return double
     */
    double modulus() const;

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
    Complex& operator=(Complex const& other);

    /**
     * @brief Move assignment overload. Moves the value of `other` to this object
     * and sets `other` to default values
     *
     * @param other object to move
     * @return Complex&
     */
    Complex& operator=(Complex&& other) noexcept;

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
    friend Complex operator*(Complex const& lhs, Complex const& rhs) {
        // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
        return Complex((lhs.real_num_ * rhs.real_num_) - (lhs.imaginary_num_ * rhs.imaginary_num_),
                       (lhs.real_num_ * rhs.imaginary_num_) + (lhs.imaginary_num_ * rhs.real_num_));
    }

    /**
     * @brief Checks if `lhs` and `rhs` are the same complex number
     *
     * @param lhs
     * @param rhs
     * @return true
     * @return false
     */
    friend bool operator==(Complex const& lhs, Complex const& rhs) {
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
        return !(lhs == rhs); // NOTE how I am using an overload that already exists
    }

    /**
     * @brief Writes the complex number in the form of a+bi to the output stream
     *
     * @param os output stream to write to
     * @param z complex number to write
     * @return std::ostream&
     */
    friend std::ostream& operator<<(std::ostream& os, Complex const& z) {
        // NOTE If z.imaginary_num_ is negative, the minus sign is automatically printed
        os << z.real_num_ << (z.imaginary_num_ < 0 ? "" : "+") << z.imaginary_num_ << "i";
        return os;
    }

  private:
    double real_num_;
    double imaginary_num_;
};

#endif // COMPLEX_HPP