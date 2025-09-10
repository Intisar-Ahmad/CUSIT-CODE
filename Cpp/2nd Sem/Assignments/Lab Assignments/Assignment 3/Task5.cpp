/*
Task 5: Constructor Signatures
1. Create a new class named Car.
2. Inside the class, add three constructors:
   • A default constructor with no parameters. Print:
     "Default constructor called"
   • A constructor with one parameter (string brand). Print:
     "1 parameter constructor called"
   • A constructor with two parameters (string brand, int year). Print:
     "2 parameter constructor called"
3. In main():
   • Create a Car object with no arguments.
   • Create one with only the brand.
   • Create one with brand and year.
*/

#include <iostream>
using namespace std;

class Car {
public:
    // Default constructor
    Car() {
        cout << "Default constructor called" << endl;
    }

    // Constructor with one parameter
    Car(string brand) {
        cout << "1 parameter constructor called" << endl;
        cout << "Brand: " << brand << endl;
    }

    // Constructor with two parameters
    Car(string brand, int year) {
        cout << "2 parameter constructor called" << endl;
        cout << "Brand: " << brand << ", Year: " << year << endl;
    }
};

int main() {
    Car c1;                     
    Car c2("Toyota");           
    Car c3("Honda", 2022);      
    return 0;
}
