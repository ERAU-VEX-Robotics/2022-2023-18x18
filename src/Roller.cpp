#include "Roller.hpp"
#include "pros/motors.h"

Roller::Roller(std::initializer_list<int> ports,
               std::initializer_list<bool> revs, double gear_ratio)
    : motors(ports, revs), gear_ratio(gear_ratio) {
    motors.set_brake_mode(pros::E_MOTOR_BRAKE_BRAKE)
}

void Roller::clockwise() { motors.move(127); }
void Roller::counterclockwise() { motors.move(-127); }

void Roller::clockwise(double degrees) {
    motors.move_relative(degrees / gear_ratio, 200);
}

void Roller::counterclockwise(double degrees) {
    motors.move_relative(-degrees / gear_ratio, 200);
}