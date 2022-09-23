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
    Robot(std::string const& name, int const& num_wheels)
    : Robot(name, num_wheels, 0) {}

    /**
     * @brief Construct a new Robot object with a name `name`, `num_wheels` wheels, and
     * `num_sensors` ultrasonic sensors
     *
     * @param name name of robot
     * @param num_wheels number of wheels
     * @param num_sensors number of ultrasonic sensors
     */
    Robot(std::string const& name, int const& num_wheels, int const& num_sensors)
    : name_{name}
    , num_wheels_{num_wheels}
    , num_sensors_{num_sensors}
    , posX_(0)
    , posY_(0) {
        if (this->num_sensors_ < 0) {
            std::cerr << "You just created a robot with negative number of sensors" << std::endl;
        }
        if (this->num_wheels_ < 0) {
            std::cerr << "You just created a robot with negative number of wheels" << std::endl;
        }
    }

    /**
     * @brief Copy constructor
     *
     * @param other
     */
    Robot(Robot const& other)
    : Robot(other.name_, other.num_wheels_, other.num_sensors_) {
        this->posX_ = other.posX_;
        this->posY_ = other.posY_;
    }

    /**
     * @brief Move constructor
     *
     * @param other
     */
    Robot(Robot&& other) noexcept
    : name_{std::move(other.name_)}
    , num_wheels_{std::move(other.num_wheels_)}
    , num_sensors_{std::move(other.num_sensors_)}
    , posX_{std::move(other.posX_)}
    , posY_{std::move(other.posY_)} {
        // Invalidate/reset
        other.name_ = std::string();
        other.num_wheels_ = 0;
        other.num_sensors_ = 0;
        other.posX_ = 0;
        other.posY_ = 0;
    }

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
    static std::pair<double, double> cartesian_to_polar(std::pair<double, double> const& val) {
        auto posX = val.first;
        auto posY = val.second;
        auto radius = std::sqrt(posX * posX + posY * posY);
        auto angle = std::atan2(posY, posX);
        return std::make_pair(radius, angle);
    }

    /**
     * @brief Write to output stream
     *
     * @param os
     * @param robot
     * @return std::ostream&
     */
    friend std::ostream& operator<<(std::ostream& os, Robot const& robot) {
        auto const polar = robot.localise();
        os << robot.getName() << "," << robot.getNumWheels() << "," << robot.getNumSensors() << "("
           << robot.posX_ << ", " << robot.posY_ << ") (" << polar.first << ", " << polar.second
           << ")" << std::endl;
        return os;
    }

    /**
     * @brief Inputs the x then y coordinates for the robot
     *
     * @param is
     * @param robot
     * @return std::istream&
     */
    friend std::istream& operator<<(std::istream& is, Robot& robot) {
        is >> robot.posX_ >> robot.posY_;
        return is;
    }

  private:
    std::string name_;
    int num_wheels_;
    int num_sensors_;
    double posX_;
    double posY_;
};

#endif // ROBOT_HPP