#include "Drivetrain.hpp"
#include "pros/misc.h"

Drivetrain::Drivetrain(std::initializer_list<int> left_ports,
                       std::initializer_list<int> right_ports,
                       std::initializer_list<bool> left_revs,
                       std::initializer_list<bool> right_revs)
    : left_motors(left_ports, left_revs),
      right_motors(right_ports, right_revs) {
    left_motors.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    right_motors.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
}

void Drivetrain::tank_driver(pros::controller_id_e_t controller) {
    left_motors.move(pros::c::controller_get_analog(
        controller, pros::E_CONTROLLER_ANALOG_LEFT_Y));
    right_motors.move(pros::c::controller_get_analog(
        controller, pros::E_CONTROLLER_ANALOG_RIGHT_Y));
}

void Drivetrain::print_left_current_draws() {
    for (int draw : left_motors.get_current_draws())
        printf("%d ", draw);
    printf("\n");
}

void Drivetrain::print_right_current_draws() {
    for (int draw : right_motors.get_current_draws())
        printf("%d ", draw);
    printf("\n");
}

void Drivetrain::print_left_voltages() {
    for (int voltage : left_motors.get_voltages())
        printf("%d ", voltage);
    printf("\n");
}

void Drivetrain::print_right_voltages() {
    for (int voltage : right_motors.get_voltages())
        printf("%d ", voltage);
    printf("\n");
}