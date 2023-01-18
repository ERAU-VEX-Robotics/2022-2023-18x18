#include "Flywheel.hpp"
#include "pros/rtos.h"
#include "utils.h"
#include <cmath>
#include <iostream>

Flywheel::Flywheel(std::initializer_list<int> ports,
                   std::initializer_list<bool> reverses)
    : motors(ports, reverses) {
    motors.set_encoder_units(pros::E_MOTOR_ENCODER_DEGREES);
    /**
     * The motor uses a 3D-printed replacement for the gear cartridge to
     * directly drive the axle from the output of the motor, which yields an RPM
     * of 3600 from the motor. However, this is not an option to set the motor's
     * gearing to, so I approximate using the maximum internal motor cartridge,
     * which is 600 RPM. This value is important for the move_velocity function
     * used to run the motors, in case I need to use that function.
     */
    motors.set_gearing(pros::E_MOTOR_GEAR_BLUE);
    motors.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void Flywheel::pid_task_fn() {
    double integral = 0;
    double prev_error = 0;
    double error = 0;

    while (1) {
        error = flywheel_velo - motors.get_avg_velocity();
        double voltage = pid(kP, kI, kD, error, &integral, &prev_error);

        if (fabs(voltage) > 12000)
            voltage = copysign(12000, voltage);

        std::cout << "Motor Voltage: " << voltage << std::endl;
        std::cout << "Motor Velocity: " << motors.get_avg_velocity()
                  << std::endl;

        motors.move_voltage(voltage);
        pros::delay(20);
    }
}

void Flywheel::trampoline(void *param) {
    if (param) {
        Flywheel *that = static_cast<Flywheel *>(param);
        that->pid_task_fn();
    }
}

void Flywheel::init_pid_task() {
    pid_task =
        pros::c::task_create(trampoline, this, TASK_PRIORITY_DEFAULT,
                             TASK_STACK_DEPTH_DEFAULT, "Flywheel PID Task");
}

void Flywheel::end_pid_task() { pros::c::task_delete(pid_task); }

void Flywheel::set_pid_consts(double Pconst, double Iconst, double Dconst) {
    kP = Pconst;
    kI = Iconst;
    kD = Dconst;
}

void Flywheel::driver(pros::controller_id_e_t controller,
                      pros::controller_digital_e_t pwr_button) {
    static bool enabled = true;
    if (enabled)
        set_velocity(flywheel_velo);
    else
        stop();
}

void Flywheel::set_velocity(int16_t velocity) {
    // Divide velocity by 6 to bring it within valid values for move_velocity
    motors.move_velocity(velocity / 6);
}

void Flywheel::stop() { motors.brake(); }