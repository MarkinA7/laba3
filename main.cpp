#include <iostream>
#include <string>
using namespace std;

class Automobile {
protected:
    string model;   
    double maxSpeed; 

public:
    Automobile(const string& mdl, double speed)
        : model(mdl), maxSpeed(speed) {}
#ifdef USE_VIRTUAL
    virtual
#endif
    void print() const {
        cout << "Модель: " << model << ", Макс. скорость: " << maxSpeed << " км/ч";
    }
};

class Bus : public Automobile {
private:
    int maxPassengers; 

public:
    Bus(const string& mdl, double speed, int passengers)
        : Automobile(mdl, speed), maxPassengers(passengers) {}

    void print() const override {  
        Automobile::print();       
        cout << ", Пассажировместимость: " << maxPassengers << " чел.";
    }
};

int main() {
    Automobile car("Toyota Camry", 220);
    Bus bus("ЛиАЗ-5292", 110, 85);

    cout << "=== Прямой вызов методов ===" << endl;
    car.print();   
    cout << endl;
    bus.print();   
    cout << endl << endl;

    Automobile* ptr;

    cout << "=== Демонстрация полиморфизма через указатель на базовый класс ===" << endl;

    ptr = &car;
    ptr->print();   
    cout << endl;

    ptr = &bus;
    ptr->print();   
    cout << endl;

#ifdef USE_VIRTUAL
    cout << "\n*** Динамический полиморфизм (virtual включён) ***\n";
    cout << "Вызван метод Bus::print(), т.к. фактический тип объекта – Bus.\n";
#else
    cout << "\n*** Статический полиморфизм (virtual выключен) ***\n";
    cout << "Вызван метод Automobile::print(), т.к. тип указателя – Automobile*.\n";
    cout << "Чтобы увидеть динамический полиморфизм, раскомментируйте '#define USE_VIRTUAL'\n";
#endif

    return 0;
}
