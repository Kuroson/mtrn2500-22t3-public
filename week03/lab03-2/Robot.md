# 1. Exercise: Simple Robot

`Robot` models an `n`-wheeled robot with `m` ultrasonic sensors.

- The robot must always have a name to identify it.
- The number of wheels and ultrasonic sensors on the robot is fixed upon creation.
- Has an x and y position. The initial position is always (0, 0).
- Assume distance is in metres and angles are in radians.

Implement `Robot` according to the following specification:

<table>
    <tr>
        <th>Method</th>
        <th>Description</th>
        <th>Usage</th>
        <th>Exceptions</th>
    </tr>
    <tr>
        <td><code>Robot(std::string const& name, int const& n)</code></td>
        <td>Constructs a robot with a <code>name</code>, <code>n</code> wheels, and no sensors.</td>
        <td><pre><code>Robot robot("robot", 3);</code></pre></td>
        <td>Prints to <code>std::cerr</code> if <code>n</code> is negative.</td>
    </tr>
    <tr>
        <td><code>Robot(std::string const& name, int const& n, int const& m)</code></td>
        <td>Constructs a robot with a <code>name</code>, <code>n</code> wheels, and <code>m</code> sensors.</td>
        <td><pre><code>Robot robot("robot", 2, 4);</code></pre></td>
        <td>Prints to <code>std::cerr</code> if <code>n</code> or <code>m</code> is negative.</td>
    </tr>
    <tr>
        <td><code>std::string getName()</code></td>
        <td>Gets the name of the robot.</td>
        <td><pre><code>std::string name{robot.getName()};</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>int getNumWheels()</code></td>
        <td>Gets the number of robot wheels.</td>
        <td><pre><code>int num_wheels{robot.getNumWheels()};</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>int getNumSensors()</code></td>
        <td>Gets the number of robot sensors.</td>
        <td><pre><code>int num_sensors{robot.getNumSensors()};</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>void setName(std::string const& name)</code></td>
        <td>Sets the name of the robot to the name provided by the argument.</td>
        <td><pre><code>robot.setName("robot2");</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>void move(double x, double y)</code></td>
        <td>Moves the robot to the new position.</td>
        <td><pre><code>Robot r("r", 2, 0); // (0, 0)
r.move(1.1, 2.2); // (1.1, 2.2)</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>std::pair&lt;double, double&gt; localise()</code></td>
        <td>Gets the polar coordinates of the robot with respect to (0, 0).</td>
        <td><pre><code>Robot r("r", 2, 0);
r.move(3, 4);
std::pair&lt;double, double&gt; p{r.localise}; // (5, 0.9273)</code></pre></td>
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

# 2. Exercise: Simple Robot (Continued)

Take the `Robot` class from **lab02-1** and extend it with the following specification:

<table>
    <tr>
        <th>Method</th>
        <th>Description</th>
        <th>Usage</th>
        <th>Exceptions</th>
    </tr>
    <tr>
        <td><code>Robot(Robot const& r)</code></td>
        <td>Copy constructor. </td>
        <td><pre><code>Robot r1("r1", 2, 0);
Robot r2(r1);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Robot(Robot&& r)</code></td>
        <td>Move constructor. </td>
        <td><pre><code>Robot r1("r1", 2, 0);
Robot r2(std::move(r1));</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Robot& operator=(Robot const& r)</code></td>
        <td>Copy assignment.</td>
        <td><pre><code>Robot r1("r1", 2, 0);
Robot r2("r2", 2, 0);
r1 = r2;</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>Robot& operator=(Robot&& r)</code></td>
        <td>Move assignment.</td>
        <td><pre><code>Robot r1("r1", 2, 0);
Robot r2("r2", 2, 0);
r1 = std::move(r2);</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>static std::pair&lt;double, double&gt; cartesian_to_polar(std::pair&lt;double, double&gt; const& val)</code></td>
        <td>Converts a cartesian coordinate to polar coordinate.</td>
        <td><pre><code>std::pair&lt;double, double&gt; carte{3, 4};
std::pair&lt;double, double&gt; polar{Robot::cartesian_to_polar(carte)}; // (5, 0.9273)</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend std::ostream& operator&lt;&lt;(std::ostream& os, Robot const& r)</code></td>
        <td>Writes the name, number of wheels, number of sensors, cartesian coordinates, and polar coordinates of the robot.</td>
        <td><pre><code>Robot r("r", 4, 7);
r.move(3, 4);
std::cout &lt;&lt; r; // "r", 4, 7, (3, 4), (5, 0.9273)</code></pre></td>
        <td>None</td>
    </tr>
    <tr>
        <td><code>friend std::istream& operator&lt;&lt;(std::istream& is, Robot& r)</code></td>
        <td>Inputs the <code>x</code> then <code>y</code> coordinates for the robot. It is equivalent to <code>r.move(x, y)</code>.</td>
        <td><pre><code>Robot r("r", 4, 7);
std::cin >> r; // 3 4</code></pre></td>
        <td>None</td>
    </tr>
</table>

In addition to the above specification, you must:

- Implement `const`-correctness for methods and member variables.
- Mark appropriate constructors, assignments, and destructor as`default` or `delete`.
- Have correct access specifiers.
- Write more tests for the new methods.
