#ifndef FLYWHEEL_HPP
#define FLYWHEEL_HPP

/**
 * \file Flywheel.hpp
 *
 * This file contains the class declaration for the Flywheel class.
 * This class represents the physical flywheel used to launch the
 * disks
 */
#include "Motor_Group.hpp"
#include "pros/misc.h"
#include <initializer_list>

class Flywheel {
  private:
    // The motor group containing all of the motors on the flywheel
    Motor_Group motors;

    const int flywheel_velo = 3600;

  public:
    /**
     * The Constructor for the Intake Class
     *
     * \param ports A list of ports used by motors on the flywheel
     * \param reverses A list of booleans specifying which motors are reversed
     *             Each element in the list corresponds to the respective
     *             element in ports, i.e. whether or not the motor in the port
     *             specified in the third index of ports is determined by the
     *             third index of revs.
     */
    Flywheel(std::initializer_list<int> ports,
             std::initializer_list<bool> reverses);

    /**
     * Function: driver
     *
     * This function allows for starting and stopping of the flywheel in driver
     * control
     */
    void driver(pros::controller_id_e_t controller,
                pros::controller_digital_e_t pwr_button);

    /**
     * Function: set_velocity
     *
     * This function sets the target velocity for the motors running the
     * flywheel.
     */
    void set_velocity(int16_t velocity);

    /**
     * Function: stop
     *
     * This function stops the flywheel.
     */
    void stop();

    /**
     * Function: print_telemetry
     *
     * This function allows for the printing of various telemetry information
     * from the motors in the Motor_Group. It wraps the call to
     * Motor_Group::print_telemetry. See that function for more information
     *
     * \param vals_to_print A bitfield specifying which values to print. See
     *                      Motor_Group::print_telemetry for more information
     */
    void print_telemetry(uint8_t vals_to_print);
};

#endif /* Flywheel.hpp */