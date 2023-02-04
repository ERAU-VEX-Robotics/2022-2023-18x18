#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    // flywheel.resume_pid_task();
    drive.init_pid_task();
    // flywheel.pause_pid_task();

    // Move to grab disk in front of bot
    drive.move_straight(48);
    drive.wait_until_settled();

    // Aim and Fire 3 disks
    drive.turn_angle(25);
    drive.wait_until_settled();

    drive.move_straight(10);
    drive.wait_until_settled();

    // Grab a few more disks
    drive.turn_angle(-125);
    drive.wait_until_settled();

    drive.move_straight(16);
    drive.wait_until_settled();

    drive.turn_angle(40);
    drive.wait_until_settled();

    drive.move_straight(34);
    drive.wait_until_settled();

    // Aim to fire more disks
    drive.turn_angle(100);
    drive.wait_until_settled();

    drive.move_straight(10);
    drive.wait_until_settled();

    drive.end_pid_task();
}