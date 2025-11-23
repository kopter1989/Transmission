#ifndef TRANSMISSION_TRANSMISSION_H
#define TRANSMISSION_TRANSMISSION_H

#endif //TRANSMISSION_TRANSMISSION_H
#include "gear.h"
#include "trust_bearing.h"
//#include "radial_bearing.h"

class Transmission {
private:
    Gear g;
    Radial_bearing rb;
    Trust_bearing tb;
    Gear gears[5];

    double dt = 0.006;
    double heat = 0.0;
    double axial_force = 0.0;
    double normal_force = 0.0;
    double rpm = 0.0;
    double temperature_of_oil = 288.0;
    double moment_friction = 0.0;


public:
    void update();
    void set_dt(double dt_);
    void set_axial_force(double axial_force_);
    void set_normal_force(double normal_force_);
    void set_temperature_of_oil(double temperature_of_oil_);
    void set_rpm(double rpm_);

    double get_dt() { return dt; };
    double get_heat() { return heat; };
    double get_moment_friction() { return moment_friction; };
    Radial_bearing get_rb() { return rb; };
    Gear& get_gear(int number) { return gears[number]; };

};

