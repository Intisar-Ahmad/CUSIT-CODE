#include <iostream>
using namespace std;

class Engine {// removed the Ford class
public:
    string engineType;
    int horsePower;

};

class Vehicle {//used composition (used Engine)
protected:
    string name;
    string model;
    Engine engine;

public:

    virtual void accelerate() {
        cout << " is accelerating." << endl;
    }

    virtual void brake() {
        cout << name << " is braking." << endl;
    }
};

class GTR : public Vehicle {//Inheritance
public:

    void boost() {
        cout  << " is using boost mode!" << endl;
    }
};
