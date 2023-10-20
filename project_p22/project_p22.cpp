#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include "kontrolPunkt.h"
#include <windows.h>
#pragma warning(disable : 4996)
using namespace std;


//2023-10-19.19:44:40
int main() {
    setlocale(LC_ALL, "Russian");

    ControlPunkt kt;
    Visitor vs("Goguz", "Goguzov", "123456789");
    Visitor vs1("Robot", "Robotov", "123456789");
    Visitor vs2("Chingishan", "Chingishanov", "123456789");
    kt.registration_input(vs);
    cout << kt.getNow_count() << endl;
    kt.registration_input(vs1);
    cout << kt.getNow_count() << endl;
    kt.registration_input(vs2);
    cout << kt.getNow_count() << endl;
    kt.registration_exit(vs);
    cout << kt.getNow_count() << endl;
    kt.registration_exit(vs1);
    cout << kt.getNow_count() << endl;
    kt.registration_exit(vs2);

    kt.print_visitors();
    kt.write_visitors_in_file();
}