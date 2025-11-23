#ifndef TRANSMISSION_GEAR_H
#define TRANSMISSION_GEAR_H

#endif //TRANSMISSION_GEAR_H

#include <iostream>
#include "radial_bearing.h"

class Gear {
private:
    double dt = 0.006;
    double heat = 0.0;
    double viscosity = 0.0;
    double temperature_of_oil = 288.0;
    int z = 40;   //number of teeth
    double rpm = 0.0;
    double diameter = 0.2;  //m
    double moment = 0.0;
    double moment_out = 0.0;
    double power_out = 0.0;
    double moment_out_with_friction_prev = 0.0;
    double f_expon = 3.7;
    Radial_bearing r_1;
    Radial_bearing r_2;
    double moment_friction = 0.0;
    double moment_viscous_friction = 0.0;
    double moment_friction_between_tooths = 0.0;
    double moment_total = 0.0;
    double power_total = 0.0;
    double force = 0.0;
public:
    void update(double moment_add);
    void set_z(int z_) { z = z_; };
    int get_z() { return z; };
    void set_dt(double dt_) { dt = dt_; };
    double get_dt() { return dt; };
    void set_rpm(double rpm_) { rpm = rpm_; };
    double get_rpm() { return rpm; };
    void set_diameter(double diameter_) { diameter = diameter_; };
    void set_f_exp(double f_exp_) { f_expon = f_exp_; };
    double get_heat() { return heat; };
    void set_moment_out(double moment) { moment_out = moment; };
    void set_power_out(double power) { power_out = power; };
    double get_moment_out() { return moment_out; };
    double get_moment_total() { return moment_total; };
    void set_temperature_of_oil(double temperature_of_oil_);
};