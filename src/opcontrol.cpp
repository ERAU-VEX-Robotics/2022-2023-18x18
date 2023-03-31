#include "externs.hpp"
#include "main.h"
#include "pros/misc.h"
#include "pros/rtos.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    flywheel.resume_task();
    int voltage = 0;

    while (true) {

        flywheel.set_voltage(voltage);
        pros::delay(1000);

        flywheel.print_telemetry(E_MOTOR_GROUP_TELEM_PRINT_VOLTAGE |
                                 E_MOTOR_GROUP_TELEM_PRINT_VELOCITY);

        voltage += 50;

        /*
        flywheel.driver(pros::E_CONTROLLER_MASTER,
        pros::E_CONTROLLER_DIGITAL_A, pros::E_CONTROLLER_DIGITAL_B);
        */
    }
    flywheel.end_task();
}
