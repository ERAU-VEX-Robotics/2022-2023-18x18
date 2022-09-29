/**
 * \file Drivetrain.hpp
 * This file contains the class declaration for the Drivetrain class.
 * This class represents the drivetrain subsystem. It allows easy
 * control of the motors on the drivetrain in both drivetrain and
 * autonomous
 */

#ifndef DRIVETRAIN_HPP
#define DRIVETRAIN_HPP

#include <initializer_list>

#include "Motor_Group.hpp"
#include "pros/misc.h"

class Drivetrain {
  private:
    Motor_Group left_motors, right_motors;

  public:
    Drivetrain(std::initializer_list<int> leftPorts,
               std::initializer_list<int> rightPorts,
               std::initializer_list<bool> leftRevs,
               std::initializer_list<bool> rightBools);

    void tank_driver(pros::controller_id_e_t controller);
    void arcade_driver(pros::controller_id_e_t controller);

    void print_left_current_draws();

    void print_right_current_draws();

    void print_left_voltages();

    void print_right_voltages();
};

#endif /* Drivetrain.hpp */