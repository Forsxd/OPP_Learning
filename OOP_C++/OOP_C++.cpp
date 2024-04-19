#include <iostream>
#include <string>

using namespace std;

class Car;

class sevenforce {
public:
    void stage1(Car& car);
    void stage2(Car& car);
    void stage3(Car& car);
};

class Car
{
    friend sevenforce;

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
        cout << "Блять нахуй " << name << " машина готова " << name << endl;
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
        cout << "Блять нахуй " << name << " уничтожена к ебени фени" << endl;
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
    void printMessage();
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
            cout << "Напряга есть" << endl;
        }
        else
        {
            cout << "без напряги 💀💀💀" << endl;
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
        cout << "data created" << endl;
    }
    Test(const Test& other) {
        cout << "copy of data created" << endl;
        this->Size = other.Size;
        this->data = new int[other.Size];
        for (int i = 0; i < other.Size; i++)
        {
            this->data[i] = other.data[i];
        }
    }
    ~Test() {
        cout << "drop table" << endl;
        delete[] data;
    }
};

void foo(Test value) {
    cout << "foo called" << endl;
}

Test foo2() {
    cout << "foo2 called" << endl;
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
    void print() {
        cout << x << " " << y << endl;
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }
    void setPoint(int x, int y) {
        this->x = x;
        this->y = y;
    }
    Point & operator ++() {
        this->x += 1;
        this->y++;
        return *this;
    }
    Point& operator ++(int val) {
        Point temp(*this);
        this->x++;
        this->y++;
        return temp;
    }
    friend void changeX(Point& a);
};

void changeX(Point& a) {
    a.x = 5;
}

class Massiv{
private:
    int arr[5]{ 47, 78, 3, 96, 16 };
public:
    int& operator [](int index) {
        return arr[index];
    }
};

class Human {
private:
    int year;
    int weight;
    string name;
public:
    void print() {
        cout << "Имя: " << name << endl << "Вес: " << weight << endl << "Год: " << year << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    int a = 5;
    int* b = &a;
    cout << *b << endl;
}

void Car::printMessage() {
    cout << name << endl;
}

void sevenforce::stage1(Car& car) {
    car.bhp += 75;
    car.torque += 120;
}

void sevenforce::stage2(Car& car) {
    car.bhp += 150;
    car.torque += 200;
}

void sevenforce::stage3(Car& car) {
    car.bhp += 285;
    car.torque += 355;
    car.liters += 0.4;
}