#include <iostream>
using namespace std;

/*
Write a C++ program that defines a class "Employee" with attributes for name, employeeID, and salary. 
Implement a parameterized constructor to initialize these attributes when an object is created 
and a destructor that displays a message when an object is destroyed. 
Additionally, include a displayInfo() function to print the employee’s details. 
Inside the main() function, create multiple objects to observe the constructor and destructor execution sequence.
*/

class Employee {
private:
    string name;
    int employeeID;
    double salary;

public:
    Employee(string n, int id, double s) : name(n), employeeID(id), salary(s) {
        cout << "Employee object created for " << name << endl;
    }

    ~Employee() {
        cout << "Employee object destroyed for " << name << endl;
    }

    void displayInfo() {
        cout << "Name: " << name << ", Employee ID: " << employeeID << ", Salary: $" << salary << endl;
    }
};

int main() {
    Employee e1("Bhino1", 201, 50000);
    Employee e2("Bhino2", 202, 60000);
    e1.displayInfo();
    e2.displayInfo();
    return 0;
}
