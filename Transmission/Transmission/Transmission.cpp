#include "transmission.h"

void Transmission::update() {
    //g.update();
    //rb.update();
    //tb.update();

    for (auto i = std::begin(gears); i != std::end(gears); i++) {   //передаем обороты на шестерни
        i->set_temperature_of_oil(temperature_of_oil);
        if (i == std::begin(gears)) i->set_rps(rps);
        else {
            i->set_rps((i - 1)->get_rps() * (i - 1)->get_z() / i->get_z());
        }
    }

    for (int a = sizeof(gears) / sizeof(gears[0]) - 1; a > -1; a--) {
        if (a == sizeof(gears) / sizeof(gears[0]) - 1) {
            get_gear(a).update(0.0);
        }
        else {
            // i->set_moment_out(i->get_moment_out() + (i - 1)->get_moment_total());
            get_gear(a).update(get_gear(a + 1).get_moment_total());
            //a->update((a + 1)->get_moment_total());
        }
    }
    


    rb.set_dt(dt);
    rb.set_normal_force(normal_force);
    rb.set_rps(rps);
    rb.set_temperature_of_oil(temperature_of_oil);
    rb.update();
    heat = rb.get_heat();
    moment_friction = rb.get_moment_friction();
}

void Transmission::set_dt(double dt_) {
    if (dt_ < 0) dt_ = 0.0;
    dt = dt_;
    rb.set_dt(dt_);
}

void Transmission::set_axial_force(double axial_force_) {
    if (axial_force_ < 0) axial_force_ = 0.0;
    axial_force = axial_force_;
}

void Transmission::set_normal_force(double normal_force_) {
    if (normal_force_ < 0) normal_force_ = 0.0;
    normal_force = normal_force_;
    rb.set_normal_force(normal_force_);
}

void Transmission::set_temperature_of_oil(double temperature_of_oil_) {
    if (temperature_of_oil_ < 1.0) temperature_of_oil_ = 1.0;
    temperature_of_oil = temperature_of_oil_;
    rb.set_temperature_of_oil(temperature_of_oil_);
};

void Transmission::set_rps(double rps_) {
    if (rps_ < 0) rps_ = 0.0;
    rps = rps_;
    rb.set_rps(rps_);
}


