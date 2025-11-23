//#include <math.h>
//#include <cmath>
#include "trust_bearing.h"
#define _USE_MATH_DEFINES // for C++
#include <cmath>

void Trust_bearing::update() {
    viscosity = exp(f_exp / temperature_of_oil);
    moment_rpm = viscosity * rpm;
    moment_rpm = pow(moment_rpm, 0.66);
    moment_rpm *= f_0;

    moment_static = f_1 * normal_force;
    moment_static += f_2 * axial_force;

    moment_friction = moment_rpm + moment_static;

    heat = dt * moment_friction * 2 * M_PI * rpm / 60;
}