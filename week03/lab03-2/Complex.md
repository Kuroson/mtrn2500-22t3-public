# 1. Exercise: Complex

`Complex` models a complex number of the form `z = a + ib` where:

- `a` is a real number.
- `b` is a real number.

Implement `Complex` according to the following specification:

<table>
    <tr>
        <th>Method</th>
        <th>Description</th>
        <th>Usage</th>
        <th>Exceptions</th>
    </tr>
    <tr>
        <td><code>Complex()</code></td>
        <td>Constructs a complex number with no real and no imaginary component.</td>
        <td><pre><code>Complex z; // z = 0 + 0i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Complex(double const& real)</code></td>
        <td>Constructs a complex number with a real component but no imaginary component.</td>
        <td><pre><code>Complex z(42); // z = 42 + 0i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Complex(double const& real, double const& imaginary)</code></td>
        <td>Constructs a complex number with a real and imaginary component.</td>
        <td><pre><code>Complex z(42, 75); // z = 42 + 75i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>~Complex()</code></td>
        <td>Destructor.</td>
        <td><pre><code></code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Complex conjugate()</code></td>
        <td>Returns the conjugate of <code>*this</code>.</td>
        <td><pre><code>Complex z1(42, 75); // z1 = 42 + 75i
Complex z2{z1.conjugate()}; // z2 = 42 - 75i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>double modulus()</code></td>
        <td>Returns the modulus of <code>*this</code</td>
        <td><pre><code>Complex z(3, 4); // z = 3 + 4i
double mod{z.modulus()}; // mod = 5</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>double argument()</code></td>
        <td>Returns the argument of <code>*this</code>.</td>
        <td><pre><code>Complex z(3, 4); // z = 3 + 4i
double arg{z.argument()}; // arg = 0.9273</code></pre></td>
        <td>None</td>
    </tr>
</table>

In addition to the above specification, you must:

- Implement `const`-correctness for methods and member variables.
- Mark the default constructor as `default` or `delete`.
- Mark the destructor as `default` or `delete`.
- Use initialiser lists where required.
- Use delegating constructors where possible.
- Have correct access specifiers.

# 2. Exercise: Complex (Continued)

Take the `Complex` class from **lab02-1** and extend it with the following specification:

<table>
    <tr>
        <th>Method</th>
        <th>Description</th>
        <th>Usage</th>
        <th>Exceptions</th>
    </tr>
    <tr>
        <td><code>Complex(Complex const& z)</code></td>
        <td>Copy constructor. </td>
        <td><pre><code>Complex z1;
Complex z2(z1);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Complex(Complex&& z)</code></td>
        <td>Move constructor. </td>
        <td><pre><code>Complex z1;
Complex z2(std::move(z1));</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Complex& operator=(Complex const& z)</code></td>
        <td>Copy assignment. </td>
        <td><pre><code>Complex z1;
Complex z2;
z2 = z1;</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Complex& operator=(Complex&& z)</code></td>
        <td>Move assignment. </td>
        <td><pre><code>Complex z1;
Complex z2;
z2 = std::move(z1);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>static Complex make_conjugate(Complex const& z)</code></td>
        <td>Returns the conjugate of <code>z</code>. Equivalent to <code>z.conjugate()</code>.</td>
        <td><pre><code>Complex z1(42, 75); // z1 = 42 + 75i
Complex z2{Complex::make_conjugate(z1)}; // z2 = 42 - 75i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend Complex operator+(Complex const& lhs, Complex const& rhs)</code></td>
        <td>Returns the addition of two complex numbers.</td>
        <td><pre><code>Complex z1(3, 4); // z1 = 3 + 4i
Complex z2(4, 5); // z2 = 4 + 5i
Complex z3{z1 + z2}; // z3 = 7 + 9i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend Complex operator-(Complex const& lhs, Complex const& rhs)</code></td>
        <td>Returns the subtraction of two complex numbers.</td>
        <td><pre><code>Complex z1(3, 4); // z1 = 3 + 4i
Complex z2(4, 5); // z2 = 4 + 5i
Complex z3{z1 - z2}; // z3 = -1 + -1i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend Complex operator*(Complex const& lhs, Complex const& rhs)</code></td>
        <td>Returns the multiplication of two complex numbers.</td>
        <td><pre><code>Complex z1(3, 4); // z1 = 3 + 4i
Complex z2(4, 5); // z2 = 4 + 5i
Complex z3{z1 * z2}; // z3 = -8 + 31i</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend bool operator==(Complex const& lhs, Complex const& rhs)</code></td>
        <td>Returns true if real components are equal and imaginary components equal.</td>
        <td><pre><code>Complex z1(3, 4); // z1 = 3 + 4i
Complex z2(4, 5); // z2 = 4 + 5i
Complex z3(4, 5); // z3 = 4 + 5i
bool t1{z1 == z2}; // false
bool t2{z2 == z3}; // true</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend bool operator!=(Complex const& lhs, Complex const& rhs)</code></td>
        <td>Returns false if real components are equal and imaginary components equal.</td>
        <td><pre><code>Complex z1(3, 4); // z1 = 3 + 4i
Complex z2(4, 5); // z2 = 4 + 5i
Complex z3(4, 5); // z3 = 4 + 5i
bool t1{z1 != z2}; // true
bool t2{z2 != z3}; // false</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend std::ostream& operator<<(std::ostream& os, Complex const& z)</code></td>
        <td>Writes the complex number to the output in the format <code>a+bi</code> where <code>a</code> and <code>b</code> are the real and imaginary component respectively.</td>
        <td><pre><code>Complex z(3, 4); // z = 3 + 4i
std::cout &lt;&lt; z; // 3+4i</code></pre></td>
        <td>None</td>
    </tr>
</table>

In addition to the above specification, you must:

- Implement `const`-correctness for methods and member variables.
- Mark appropriate constructors, assignments, and destructor as `default` or `delete`.
- Have correct access specifiers.
- Write more tests for the new methods.
