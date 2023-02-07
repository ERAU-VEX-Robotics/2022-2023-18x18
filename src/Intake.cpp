/**
 * Function definitions for the Intake class
 */

#include "Intake.hpp"
#include "pros/misc.h"
#include <initializer_list>

Intake::Intake(std::initializer_list<int> bot_ports,
               std::initializer_list<bool> bot_reverses,
               std::initializer_list<int> top_ports,
               std::initializer_list<bool> top_reverses)
    : bot_mtrs(bot_ports, bot_reverses), top_mtrs(top_ports, top_reverses) {
    bot_mtrs.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    top_mtrs.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
}

void Intake::driver(pros::controller_id_e_t controller,
                    pros::controller_digital_e_t in_button,
                    pros::controller_digital_e_t out_button,
                    pros::controller_digital_e_t in_top_button) {
    if (pros::c::controller_get_digital(controller, in_button))
        in();
    else if (pros::c::controller_get_digital(controller, out_button))
        out();
    else if (pros::c::controller_get_digital(controller, in_top_button))
        in_top();
    else
        stop();
}

void Intake::in() {
    bot_mtrs.move(127);
    top_mtrs.move(127);
}

void Intake::out() {
    bot_mtrs.move(-127);
    top_mtrs.move(-127);
}

void Intake::in_top() { top_mtrs.move(127); }

void Intake::stop() {
    top_mtrs.move(0);
    bot_mtrs.move(0);
}

void Intake::print_telemetry(uint8_t vals_to_print) {
    printf("Intake Telemetry\n");
    printf("Top motors\n");
    top_mtrs.print_telemetry(vals_to_print);
    printf("Bottom motors\n");
    bot_mtrs.print_telemetry(vals_to_print);
}