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
    Car(string name, int bhp, int torque, double liters, string engineType, int cilinders)
    {
        this->name = name;
        this->bhp = bhp;
        this->torque = torque;
        this->liters = liters;
        this->engineType = engineType;
        this->cilinders = cilinders;
        cout << "Конструтор сконструировал " << name << endl;
    }

    void setBhp(int bhp) {
        this->bhp = bhp;
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

class Test {
private:
    int Size;
public:
    int *data;
    Test(int size) {
        this->Size = size;
        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }
        cout << "data присвоена" << endl;
    }
    Test(const Test& other) {
        cout << "copy of data присвоена" << endl;
        this->Size = other.Size;
        this->data = new int[other.Size];
        for (int i = 0; i < other.Size; i++)
        {
            this->data[i] = other.data[i];
        }
    }
    
    ~Test() {
        cout << "data отсвоена" << endl;
        delete[] data;
    }
};

void foo(Test value) {
    cout << "функция вызвалась" << endl;
}

Test foo2() {
    cout << "функция 2 вызвалась" << endl;
    Test temp(2);
    return temp;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    /*Car BMW_M5("BMW M5 F90 Cometition", 625, 750, 4.4, "V", 8);
    BMW_M5.carInfo();
    BMW_M5.setBhp(1500);
    BMW_M5.carInfo();*/
    /*Test dataTest(5);
    foo(dataTest);*/
    Test a(10);
    Test b(a);
    return 0;
}