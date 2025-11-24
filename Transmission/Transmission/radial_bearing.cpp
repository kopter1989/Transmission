//#include <math.h>
//#include <cmath>
#define _USE_MATH_DEFINES
#include <cmath>
#include "radial_bearing.h"

void Radial_bearing::update() {
    viscosity = exp(f_exp / temperature_of_oil);
    moment_rps = viscosity * rps;
    moment_rps = pow(moment_rps, 0.66);
    moment_rps *= f_0;

    moment_static = f_1 * normal_force;

    moment_friction = moment_rps + moment_static;

    heat = dt * moment_friction * 2 * M_PI * rps;
}

