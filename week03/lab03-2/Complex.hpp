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
    Complex();

    /**
     * @brief Construct a new Complex object with a real `real` component
     *
     * @param real real component
     */
    Complex(double const& real);

    /**
     * @brief Construct a new Complex object with a real `real` and imaginary `imaginary` component
     *
     * @param real real component
     * @param imaginary imaginary component
     */
    Complex(double const& real, double const& imaginary);

    /**
     * @brief Copy constructor. Creates a copy based on `other` value
     *
     * @param other object to copy
     */
    Complex(Complex const& other);
    /**
     * @brief Move constructor. Moves the value of `other` to this object
     * and then sets `other` to default values
     *
     * @param other object to move and set to default values
     */
    Complex(Complex&& other) noexcept;

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
    friend Complex operator+(Complex const& lhs, Complex const& rhs);

    /**
     * @brief Returns the subtraction of two complex numbers
     *
     * @param lhs
     * @param rhs
     * @return Complex
     */
    friend Complex operator-(Complex const& lhs, Complex const& rhs);

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
    friend bool operator==(Complex const& lhs, Complex const& rhs);

    /**
     * @brief Checks if `lhs` and `rhs` are not the same complex number
     *
     * @param lhs
     * @param rhs
     * @return true
     * @return false
     */
    friend bool operator!=(Complex const& lhs, Complex const& rhs);

    /**
     * @brief Writes the complex number in the form of a+bi to the output stream
     *
     * @param os output stream to write to
     * @param z complex number to write
     * @return std::ostream&
     */
    friend std::ostream& operator<<(std::ostream& os, Complex const& z);

  private:
    double real_num_;
    double imaginary_num_;
};

#endif // COMPLEX_HPP