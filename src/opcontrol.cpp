#include "main.h"

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
    flywheel.resume_pid_task();
    while (true) {
        flywheel.driver(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_A,
                        pros::E_CONTROLLER_DIGITAL_B);
        drive.arcade_driver(pros::E_CONTROLLER_MASTER, false);
        intake.driver(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_R1,
                      pros::E_CONTROLLER_DIGITAL_L1);
        roller.driver(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_UP,
                      pros::E_CONTROLLER_DIGITAL_DOWN);
        pros::delay(2);
    }
    flywheel.end_pid_task();
}
