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
    drive.pause_pid_task();
    bool endgame_primed = false;

    flywheel.resume_task();
    while (true) {
        flywheel.driver(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_A,
                        pros::E_CONTROLLER_DIGITAL_B);
        drive.arcade_driver(pros::E_CONTROLLER_MASTER,
                            pros::E_CONTROLLER_DIGITAL_RIGHT, false);
        intake.driver(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_R1,
                      pros::E_CONTROLLER_DIGITAL_R2);
        roller.driver(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_UP,
                      pros::E_CONTROLLER_DIGITAL_DOWN);
        indexer.driver(pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_L1,
                       pros::E_CONTROLLER_DIGITAL_L2);

        if (pros::c::controller_get_digital_new_press(
                pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_X))
            endgame_primed = true;
        if (pros::c::controller_get_digital_new_press(
                pros::E_CONTROLLER_MASTER, pros::E_CONTROLLER_DIGITAL_Y) &&
            endgame_primed)
            pros::c::adi_digital_write('a', true);
        pros::delay(2);
    }
    flywheel.end_task();
    drive.pause_pid_task();
}