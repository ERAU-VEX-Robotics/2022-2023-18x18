#include "Motor_Group.hpp"
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

    while (true) {
        drive.tank_driver(pros::E_CONTROLLER_MASTER);
        drive.print_telemetry(0, E_MOTOR_GROUP_TELEM_PRINT_CURRENT |
                                     E_MOTOR_GROUP_TELEM_PRINT_VELOCITY |
                                     E_MOTOR_GROUP_TELEM_PRINT_VOLTAGE);
        pros::delay(20);
    }
}
