#include <iostream>
using namespace std;

class Transport {
protected:
    string name;
    double weight;
    double fuelUsage;

public:
    Transport(const string& n, double w, double f) : name(n), weight(w), fuelUsage(f) {}

    virtual double calculateCost() const = 0;

    virtual void printCost() const {
        cout << name << ": Delivery cost = " << calculateCost() << endl;
    }

    virtual ~Transport() {}
};

class Car : public Transport {
    int passengers;

public:
    Car(const string& n, double w, double f, int p) : Transport(n, w, f), passengers(p) {}

    double calculateCost() const override {
        return weight * fuelUsage * 0.1;
    }
};

class Airplane : public Transport {
    int passengers;

public:
    Airplane(const string& n, double w, double f, int p) : Transport(n, w, f), passengers(p) {}

    double calculateCost() const override {
        return weight * fuelUsage * 0.5;
    }
};

class Ship : public Transport {
    int passengers;

public:
    Ship(const string& n, double w, double f, int p) : Transport(n, w, f), passengers(p) {}

    double calculateCost() const override {
        return weight * fuelUsage * 0.2;
    }
};

class Truck : public Transport {
public:
    Truck(const string& n, double w, double f) : Transport(n, w, f) {}

    double calculateCost() const override {
        return weight * fuelUsage * 0.3;
    }
};

int main() {
    Transport* transports[] = {
        new Car("Sedan", 1200, 8, 4),
        new Airplane("Boeing", 50000, 300, 150),
        new Ship("Titanic", 200000, 100, 300),
        new Truck("Volvo Truck", 8000, 20)
    };

    for (Transport* t : transports) {
        t->printCost();
        delete t;
    }
}
