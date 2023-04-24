#include "main.h"

Drivetrain drive({20, 18, 16}, {10, 8, 6}, {true, true, true},
                 {false, false, false});
Intake intake({4}, {false});
Flywheel flywheel({14}, {true});
Roller roller({1}, {false}, 36.0 / 60.0);
Indexer indexer({3}, {true});

/**
 * Runs initialization code.This occurs as soon as the program is started.
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
    // GUI init
    gui_init();

    // drive.add_adi_encoders('a', 'b', true, 'c', 'd', true);
    drive.set_pid_consts(600, 0, 0);
    drive.set_drivetrain_dimensions(12.5, 1.625, 36.0 / 60.0);
    drive.set_settled_threshold(1);

    flywheel.set_consts(1478, 19.4520, 2, 0);
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
