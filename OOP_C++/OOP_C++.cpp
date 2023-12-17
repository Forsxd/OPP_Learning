#include <iostream>
#include <string>

using namespace std;

class Car
{
public:
    int bhp;
    string name;
    double liters;
    string engineType;
    int cilinders;
    void carInfo()
    {
        cout << name << endl;
        cout << bhp << "HP\n" << liters << "L\n" << engineType << cilinders << endl << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    Car BMW_M5;
    BMW_M5.name = "BMW M5 Competition";
    BMW_M5.bhp = 625;
    BMW_M5.liters = 4.4;
    BMW_M5.engineType = "V";
    BMW_M5.cilinders = 8;
    BMW_M5.carInfo();
    Car Porshe911;
    Porshe911.name = "Porshe 911 GT3 RS";
    Porshe911.bhp = 518;
    Porshe911.liters = 4.0;
    Porshe911.engineType = "I";
    Porshe911.cilinders = 6;
    Porshe911.carInfo();
    return 0;
}