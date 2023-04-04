#include "main.h"

Drivetrain drive({20, 19, 18, 17, 16}, {10, 9, 8, 7, 6},
                 {true, false, true, false, true},
                 {false, true, false, true, false});
Intake intake({4}, {false});
Flywheel flywheel({14}, {true});
Roller roller({1}, {true}, 1);
Indexer indexer({3}, {false});

/**
 * Runs initialization code.This occurs as soon as the program is started.
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    // GUI init
    gui_init();

    // drive.add_adi_encoders('a', 'b', true, 'c', 'd', true);
    drive.set_pid_straight_consts(100, 0, 0);
    drive.set_pid_turn_consts(50, 0, 0);
    drive.set_drivetrain_dimensions(15.75, 2, 1);
    drive.set_settled_threshold(20);

    flywheel.set_consts(2137, 22.0348, 0.5, 0);
    flywheel.set_speed_slow();
    flywheel.init_task();
    flywheel.pause_task();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
