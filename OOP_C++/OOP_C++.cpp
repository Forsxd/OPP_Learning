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

class Point {
private:
    int x;
    int y;
public:
    Point() {
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    bool operator ==(const Point& other) {
        return this->x == other.x && this->y == other.y;
    }
    bool operator !=(const Point& other) {
        return this->x != other.x && this->y != other.y;
    }
    Point operator +(const Point &other) {
        Point temp;
        temp.x = this->x + other.y;
        temp.y = this->y + other.y;
        return temp;
    }
    void Print() {
        cout << x << " " << y << endl;
    }
};

class Human {
private:
    int year;
    int weight;
    string name;
public:
    void Print() {
        cout << "Имя: " << name << endl << "Вес: " << weight << endl << "Год рождения: " << year << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    Point a(5, 1);
    Point b(3, 4);
    Point c = a + b;
    c.Print();
    return 0;
}