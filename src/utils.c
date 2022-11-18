#include "utils.h"

double pid(double kP, double kI, double kD, double error, double *integral,
           double *prevError) {
    *integral += error;
    double derivative = error - *prevError;
    *prevError = error;

    return error * kP + *integral * kI + derivative * kD;
}