#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <cmath>
#include <iostream>
#include <ostream>
#include <string>
#include <utility>

class Robot {
  public:
    /**
     * @brief Construct a new Robot object with a name `name` and `num_wheels` wheels
     *
     * @param name name of robot
     * @param num_wheels number of wheels
     */
    Robot(std::string const& name, int const& num_wheels);

    /**
     * @brief Construct a new Robot object with a name `name`, `num_wheels` wheels, and
     * `num_sensors` ultrasonic sensors
     *
     * @param name name of robot
     * @param num_wheels number of wheels
     * @param num_sensors number of ultrasonic sensors
     */
    Robot(std::string const& name, int const& num_wheels, int const& num_sensors);

    /**
     * @brief Copy constructor
     *
     * @param other
     */
    Robot(Robot const& other);

    /**
     * @brief Move constructor
     *
     * @param other
     */
    Robot(Robot&& other) noexcept;

    /**
     * @brief Get the name of the robot
     *
     * @return std::string
     */
    std::string getName() const;

    /**
     * @brief Get the number of wheels
     *
     * @return int
     */
    int getNumWheels() const;

    /**
     * @brief Get the number of ultrasonic sensors
     *
     * @return int
     */
    int getNumSensors() const;

    /**
     * @brief Sets the name of the robot to `name`
     *
     * @param name name to set
     */
    void setName(std::string const& name);

    /**
     * @brief Moves the robot to the new position of `x` and `y`
     *
     * @param x x coordinate
     * @param y y coordinate
     */
    void move(double const x, double const y);

    /**
     * @brief Get the polar coordinates of the robot with respect to 0, 0
     *
     * @return std::pair<double, double> where first is the radius and second is the angle
     */
    std::pair<double, double> localise() const;

    /**
     * @brief Copy assignment
     *
     * @param other
     * @return Robot&
     */
    Robot& operator=(Robot const& other);

    /**
     * @brief Move assignment
     *
     * @param other
     * @return Robot&
     */
    Robot& operator=(Robot&& other);

    /**
     * @brief Convert to polar coordinates
     *
     * @param val
     * @return std::pair<double, double>
     */
    static std::pair<double, double> cartesian_to_polar(std::pair<double, double> const& val);
    /**
     * @brief Write to output stream
     *
     * @param os
     * @param robot
     * @return std::ostream&
     */
    friend std::ostream& operator<<(std::ostream& os, Robot const& robot);
    /**
     * @brief Inputs the x then y coordinates for the robot
     *
     * @param is
     * @param robot
     * @return std::istream&
     */
    friend std::istream& operator<<(std::istream& is, Robot& robot);

  private:
    std::string name_;
    int num_wheels_;
    int num_sensors_;
    double posX_;
    double posY_;
};

#endif // ROBOT_HPP