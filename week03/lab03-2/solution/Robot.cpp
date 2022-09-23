#include "Robot.hpp"

std::string Robot::getName() const {
    return this->name_;
}

int Robot::getNumWheels() const {
    return this->num_wheels_;
}

int Robot::getNumSensors() const {
    return this->num_sensors_;
}

void Robot::setName(std::string const& name) {
    this->name_ = name;
}

void Robot::move(double const x, double const y) {
    this->posX_ = x;
    this->posY_ = y;
}

std::pair<double, double> Robot::localise() const {
    double angle = std::atan2(this->posY_, this->posX_);
    double radius = std::sqrt(this->posX_ * this->posX_ + this->posY_ * this->posY_);
    return std::make_pair(angle, radius);
}

Robot& Robot::operator=(Robot const& other) {
    auto copy = Robot(other);
    std::swap(*this, copy);
    return *this;
}

Robot& Robot::operator=(Robot&& other) {
    // Swap
    std::swap(this->name_, other.name_);
    std::swap(this->num_wheels_, other.num_wheels_);
    std::swap(this->num_sensors_, other.num_sensors_);
    std::swap(this->posX_, other.posX_);
    std::swap(this->posY_, other.posY_);
    // Clean up
    other.name_ = std::string();
    other.num_wheels_ = 0;
    other.num_sensors_ = 0;
    other.posX_ = 0;
    other.posY_ = 0;
    return *this;
}

int main() {
    return 0;
}