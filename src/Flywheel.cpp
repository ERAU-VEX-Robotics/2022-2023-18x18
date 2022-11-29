#include "Flywheel.hpp"
#include "pros/motors.h"

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
     * used to run the motors. This function is used because it includes an
     * internal PID
     */
    motors.set_gearing(pros::E_MOTOR_GEAR_BLUE);
    motors.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
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