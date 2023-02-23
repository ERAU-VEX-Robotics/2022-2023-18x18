/**
 * \file Intake.hpp
 * This file contains the class declaration for the Intake class.
 * This class represents the subsystem used to collect disks.
 */

#ifndef INTAKE_HPP
#define INTAKE_HPP

#include <initializer_list>

#include "Motor_Group.hpp"
#include "pros/misc.h"

class Intake {
  private:
    // bot_mtrs: the motors powering the half of the intake that gets disks from
    // the ground.
    // top_mtrs: The motors that moves disks into the flywheel
    Motor_Group bot_mtrs, top_mtrs;

  public:
    /**
     * The Constructor for the Intake Class
     *
     * \param bot_ports A list of ports used by the bottom motors on the intake
     * \param bot_reverses A list of booleans specifying which bot motors are
     * reversed Each element in the list corresponds to the respective element
     * in ports, i.e. whether or not the motor in the port specified in the
     * third index of ports is determined by the third index of revs.
     * \param top_ports A list of ports used by the bottom motors on the intake
     * \param top_reverses A list of booleans specifying which top motors are
     * reversed
     */
    Intake(std::initializer_list<int> bot_ports,
           std::initializer_list<bool> bot_reverses,
           std::initializer_list<int> top_ports,
           std::initializer_list<bool> top_reverses);

    /**
     * Function: driver
     *
     * The function used to control the intake in driver control
     * \param controller The controller ID whose buttons to read
     * \param in_button The digital button ID to press to run the motors to
     *                  collect disks and push them into the flywheel
     * \param out_button The digital button ID to press to run the motors to
     *                   expel disks
     * \param in_top_button The digital button ID to only run the top motors to
     * push disks into the flywheel
     */
    void driver(pros::controller_id_e_t controller,
                pros::controller_digital_e_t in_button,
                pros::controller_digital_e_t out_button,
                pros::controller_digital_e_t in_top_button);

    // Wraps the necessary code to run the motors to collect disks
    void in(void);
    // Wraps the necessary code to run the motors to expel disks from the intake
    void out(void);
    // Wraps the necessary code to run only the top motors to push disks into
    // the flywheel
    void in_top(void);
    // Stops the intake
    void stop(void);

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
#endif /* intake.hpp */