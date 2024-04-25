#include <iostream>
#include <string>

using namespace std;

class Car;

class Sevenforce {
public:
    void stage1(Car& car);
    void stage2(Car& car);
    void stage3(Car& car);
};

class Car
{
    friend Sevenforce;

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
        cout << "Блять нахуй " << name << " машина готова " << endl;
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
    void printMessage();
};

class CoffeeGrinder
{
private:
    bool checkVolt()
    {
        int a = rand() % 220;
        if (a >= 120) {
            return true;
        }
        else {
            return false;
        }
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

class Apple {
private:
    int weight;
    string color;
    int id;
    static int count;
    int test = 5;

public:
    Apple() {
        
    }
    Apple(int weight, string color) {
        this->weight = weight;
        this->color = color;
        id = count;
        count++;
    }
    int getId() {
        cout << "id: " << id << endl;
        return 0;
    }
    static int getCount() {
        cout << "count: " << count << endl;
        return 0;
    }
    static void staticColorChanger(Apple &apple, string color) {
        apple.color = color;
    }
    void colorChanger(string color) {
        this->color = color;
    }
    void getColor() {
        cout << this->color << endl;
    }
};

void changeX(Point& a) {
    a.x = 6;
}

int Apple::count = 0;

class Massiv /*Перегрузка оператора индексирования*/ {
private:
    int arr[5]{ 47, 78, 3, 96, 16 };
public:
    int& operator [](int index) {
        return arr[index];
    }
};

class Cap /*Агрегация, типо мы кепку можем на что угодно нацепить, по этому мы ее отдельно выносим, а не в классе Human делаем(надо создать класс Cap в Human)*/ {
public:
    string getColor() {
        return color;
    }
private:
    string color = "purple";
};

class Human {
private:
    int year;
    int weight;
    string name;
    class Brain {
    public:
        void think() {
            cout << "I'm thinking" << endl;
        }
    };
    Brain brain;
    Cap cap;
public:
    Human(string name, int weight, int year) {
        this->name = name;
        this->weight = weight;
        this->year = year;
    }
    void print() {
        cout << "Name: " << name << endl << "Weight: " << weight << endl << "Year: " << year << endl;
    }
    void think() { /*Композиция, мы вызываем think у Human, а в этот момент think вызывает think у Brain(надо создать класс Brain в Human)*/
        brain.think();
    }
    void inspectCap() {
        cout << "My cap is " << cap.getColor() << endl;
    }
};

class Screan /*Вложеннные классы*/ {
private:
    class Pixel {
    private:
        int r;
        int g;
        int b;

    public:
        Pixel(int r, int g, int b) {
            this->r = r;
            this->g = g;
            this->b = b;
        }
        string getInfo() {
            return "Pixel: r = " + to_string(r) + " g = " + to_string(g) + " b = " + to_string(b);
        }
    };
    static const int LENGHT = 5;
    Pixel pixels[LENGHT]{
        Pixel(rand() % 255, rand() % 255, rand() % 255),
        Pixel(rand() % 255, rand() % 255, rand() % 255),
        Pixel(rand() % 255, rand() % 255, rand() % 255),
        Pixel(rand() % 255, rand() % 255, rand() % 255),
        Pixel(rand() % 255, rand() % 255, rand() % 255)
    };
public:
    void getScreanInfo() {
        for (int i = 0; i < LENGHT; i++)
        {
            cout << pixels[i].getInfo() << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));      
    Human human("Lol Kekovich", 52, 2003);
    human.print();
    human.think();
    human.inspectCap();
    
}

void Car::printMessage() {
    cout << name << endl;
}

void Sevenforce::stage1(Car& car) {
    car.bhp += 75;
    car.torque += 120;
    cout << "Произведен чип тюниг" << endl;
}

void Sevenforce::stage2(Car& car) {
    car.bhp += 150;
    car.torque += 200;
}

void Sevenforce::stage3(Car& car) {
    car.bhp += 285;
    car.torque += 355;
    car.liters += 0.4;
}