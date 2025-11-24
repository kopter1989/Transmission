#ifndef TRANSMISSION_TRUST_BEARING_H
#define TRANSMISSION_TRUST_BEARING_H

#endif //TRANSMISSION_TRUST_BEARING_H


class Trust_bearing {
    double dt = 0.006;
    double heat;
    long double viscosity;
    double f_0 = 0.7224;
    double f_1 = 0.0009;
    double f_2 = 0.0009;
    double f_exp = 3.7;
    double normal_force;
    double axial_force;
    double rps;
    double moment_friction;
    double moment_rps;
    double moment_static;
    double temperature_of_oil = 288.0;
public:
    void update();
    void set_dt(double dt_) { dt = dt_; };
    double get_dt() { return dt; };
    void set_temperature_of_oil(double temperature_of_oil_) { temperature_of_oil = temperature_of_oil_; };
    void set_f_0(double f_0_) { f_0 = f_0_; };
    void set_f_1(double f_1_) { f_1 = f_1_; };
    void set_f_exp(double f_exp_) { f_exp = f_exp_; };
    void set_rps(double rps_) { rps = rps_; };
    void set_normal_force(double normal_force_) { normal_force = normal_force_; };
    void set_axial_force(double axial_force_) { axial_force = axial_force_; };
    double get_moment_rps() { return moment_rps; };
    double get_moment_static() { return moment_static; };
    double get_moment_friction() { return moment_friction; };
    double get_heat() { return heat; };
};