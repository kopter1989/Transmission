//#include <iostream>
//#include <cmath>
#define _USE_MATH_DEFINES 
#include <cmath>
#include "gear.h"


void Gear::update(double moment_add) {
    viscosity = exp(f_expon / temperature_of_oil);
    moment_viscous_friction = 2e-6 * viscosity * pow(diameter, 4) * pow(rps, 2.8);
    force = moment_out / diameter / 2.0;
    moment_friction_between_tooths = 0.032 * pow(force, 0.2) * pow(viscosity, -0.05);
    moment_friction_between_tooths *= moment_add;
    moment_friction_between_tooths /= z;

    r_1.set_temperature_of_oil(temperature_of_oil);
    r_2.set_temperature_of_oil(temperature_of_oil);
    r_1.set_rps(rps);
    r_2.set_rps(rps);
    r_1.update();
    r_2.update();


    moment_total = moment_out + moment_viscous_friction + moment_friction_between_tooths;
    moment_total += r_1.get_moment_friction();
    moment_total += r_2.get_moment_friction();

    heat = dt * moment_total * 2 * M_PI * rps;
}

void Gear::set_temperature_of_oil(double temperature_of_oil_) {
    if (temperature_of_oil_ < 1.0) temperature_of_oil_ = 1.0;
    temperature_of_oil = temperature_of_oil_;
};
