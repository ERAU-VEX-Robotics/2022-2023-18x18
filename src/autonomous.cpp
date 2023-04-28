#include "externs.hpp"
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
    flywheel.resume_task();
    drive.resume_pid_task();

    // Drive PID tuning programs
    // Straight
    /*
    drive.move_straight(72);
    drive.wait_until_settled();

    drive.move_straight(-60);
    drive.wait_until_settled();

    drive.move_straight(48);
    drive.wait_until_settled();

    drive.move_straight(-36);
    drive.wait_until_settled();

    drive.move_straight(24);
    drive.wait_until_settled();

    drive.move_straight(-12);
    drive.wait_until_settled();

    drive.move_straight(6);
    drive.wait_until_settled();

    drive.move_straight(-3);
    drive.wait_until_settled();
    */

    // Turn
    /*
    drive.turn_angle(180);
    drive.wait_until_settled();

    drive.turn_angle(-150);
    drive.wait_until_settled();

    drive.turn_angle(120);
    drive.wait_until_settled();

    drive.turn_angle(-90);
    drive.wait_until_settled();

    drive.turn_angle(60);
    drive.wait_until_settled();

    drive.turn_angle(-30);
    drive.wait_until_settled();
    */

    flywheel.set_target_velo(480);

    drive.move_straight(-2);
    drive.wait_until_settled();

    pros::delay(250);
    roller.clockwise(120);
    pros::delay(250);

    drive.move_straight(2);
    drive.wait_until_settled();

    drive.turn_angle(-15);
    drive.wait_until_settled();

    pros::delay(5000);

    indexer.punch_disk();
    pros::delay(500);
    indexer.punch_disk();
    pros::delay(200);
    flywheel.pause_task();

    drive.turn_angle(-130);
    drive.wait_until_settled();

    intake.in();
    drive.move_straight(-30);
    drive.wait_until_settled();

    flywheel.resume_task();
    flywheel.set_target_velo(475);
    drive.move_straight(-3);
    drive.wait_until_settled();

    pros::delay(500);

    drive.move_straight(-3);
    drive.wait_until_settled();

    pros::delay(500);

    drive.move_straight(-3);
    drive.wait_until_settled();

    pros::delay(3000);
    intake.stop();

    drive.turn_angle(100);
    drive.wait_until_settled();

    indexer.punch_disk();
    pros::delay(200);
    indexer.punch_disk();
    pros::delay(200);
    indexer.punch_disk();

    switch (auton_id) {
    case test:
        break;
    case skills_best:
        break;
    case skills_real:
        break;
    case match_best:
        break;
    case match_real:
        break;
    case none:
        break;
    default:
        break;
    }

    flywheel.pause_task();
}