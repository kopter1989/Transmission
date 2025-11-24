#include <iostream>
#include "transmission.h"
#include <string>

int main() {
    Transmission T;
    T.set_rps(160.0);
    T.set_temperature_of_oil(380);

    for (int i = 0; i < 5; i++) { T.get_gear(i).set_moment_out(200.0); }   // устанавливаем момент на шестерни
    int z = 10;
    for (int i = 0; i < 5; i++) {            // указываем колдичество зубьев для шестерни
        T.get_gear(i).set_z(z);
        z += 10;
    }



    //for (int i = 0; i < 5; i++){ std::cout << T.get_gear(i).get_z() << std::endl; }
    //T.set_normal_force(10000.0);


    T.update();
    std::cout << T.get_gear(0).get_moment_total() << std::endl;
    //std::cout << T.get_moment_friction() << std::endl;
    //std::cout << T.get_rb().get_moment_rpm() << std::endl;
    // std::cout << T.get_rb().get_moment_static() << std::endl;
    //std::cout << T.get_heat() << std::endl;

    return 0;
}
