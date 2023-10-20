#include <iostream>
#include <string>
#include "kontrolPunkt.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    ControlPunkt kt;
    Visitor vs("Goguz", "Goguzov", "123456789");
    Visitor vs1("Robot", "Robotov", "123456789");
    Visitor vs2("Chingishan", "Chingishanov", "123456789");

    // Time and Date will be same everywhere, because program on C++ lasts less than 1 minute
    kt.registration_input(vs);
    kt.registration_input(vs1);
    kt.registration_input(vs2);

    kt.registration_exit(vs);
    kt.registration_exit(vs1);
    kt.registration_exit(vs2);

    kt.print_visitors();
    kt.write_visitors_in_file();
}