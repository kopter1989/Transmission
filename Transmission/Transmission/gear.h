#ifndef TRANSMISSION_GEAR_H
#define TRANSMISSION_GEAR_H

#endif //TRANSMISSION_GEAR_H

#include <iostream>
#include "radial_bearing.h"

class Gear {
private:
    double dt = 0.006;
    double heat = 0.0;                      //amount of heat
    double viscosity = 0.0;                //viscosity of oil
    double temperature_of_oil = 288.0;
    int z = 40;                             //number of teeth
    double f_0 = 2e-6;             //friction coefficients
    double f_1 = 0.032;
    double coef_diameter = 4.0;    //the power to which the diameter is raised
    double coef_rps = 2.8;         //  the power to which the number of revolutions is raised
    double coef_force = 0.2;     //the power to which force is raised
    double coef_viscosity = -0.05;   //the degree to which the viscosity of the oil is raised
    double rps = 0.0;
    double diameter = 0.2;                 //m
    double moment = 0.0;
    double moment_out = 0.0;
    double f_exp = 3.7;                  //coefficient for the exponent
    Radial_bearing r_1;                    //two bearings on which the gear is mounted
    Radial_bearing r_2;
    double moment_friction = 0.0;                  //total friction moment without taking into account the external moment 
    double moment_viscous_friction = 0.0;
    double moment_friction_between_tooths = 0.0;
    double moment_total = 0.0;                     //total torque on gear
    double force = 0.0;
public:
    void update(double moment_add);
    void set_z(int z_) { z = z_; };
    int get_z() { return z; };
    void set_dt(double dt_) { dt = dt_; };
    double get_dt() { return dt; };
    void set_rps(double rps_) { rps = rps_; };
    double get_rps() { return rps; };
    void set_diameter(double diameter_) { diameter = diameter_; };
    void set_f_exp(double f_exp_) { f_exp = f_exp_; };
    void set_f_0(double f_0_) { f_0 = f_0_; };
    void set_f_1(double f_1_) { f_1 = f_1_; };
    double get_heat() { return heat; };
    void set_moment_out(double moment) { moment_out = moment; };
    //void set_power_out(double power) { power_out = power; };
    double get_moment_out() { return moment_out; };
    double get_moment_total() { return moment_total; };
    void set_temperature_of_oil(double temperature_of_oil_);
    void set_coef_diameter(double coef_diameter_) { coef_diameter = coef_diameter_; };
    void set_coef_rps(double coef_rps_) { coef_rps = coef_rps_; };
    void set_coef_force(double coef_force_) { coef_force = coef_force_; };
    void set_coef_viscosity(double coef_viscosity_) { coef_viscosity = coef_viscosity_; };
};