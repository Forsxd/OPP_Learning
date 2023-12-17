#include <iostream>
#include <string>

using namespace std;

class Car
{
private:
    string name;
    int bhp;
    double liters;
    int torque;
    string engineType;
    int cilinders;
public:
    Car(string carName, int hp, int tq, double lit, string engineT, int cil)
    {
        name = carName;
        bhp = hp;
        torque = tq;
        liters = lit;
        engineType = engineT;
        cilinders = cil;
        cout << "Конструтор сконструировал " << name << endl;
    }

    Car()
    {
        name = "Name of a Car";
        bhp = 0;
        torque = 0;
        liters = 0;
        engineType = "Engine type here ";
        cilinders = 0;
    }

    ~Car()
    {
        cout << "Деструктор деструкторировал " << name << endl;
    }

    void carInfo()
    {
        cout << name << endl;
        cout << bhp << "HP\n" << torque << "Nm\n" << liters << "L\n" << engineType << cilinders << endl << endl;
    }
    string GetName()
    {
        return name;
    }

    void SetCar(string carName, int bhppower, int tq, double lit, string engineT, int cil)
    {
        name = carName;
        bhp = bhppower;
        torque = tq;
        liters = lit;
        engineType = engineT;
        cilinders = cil;
    }
};

class CoffeeGrinder
{
private:
    bool checkVolt()
    {
        return true;
    }

public:
    void start()
    {
        if (checkVolt())
        {
            cout << "Кофе перемалывается" << endl;
        }
        else
        {
            cout << "Напряжение не в норме" << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    Car BMW_M5("BMW M5 F90 Cometition", 625, 750, 4.4, "V", 8);
    BMW_M5.carInfo();
    Car Porshe911TS("Porshe 911 (992) Turbo S", 640, 800, 3.7, "F", 6);
    Porshe911TS.carInfo();
    Car placeHolder;
    placeHolder.carInfo();
    return 0;
}