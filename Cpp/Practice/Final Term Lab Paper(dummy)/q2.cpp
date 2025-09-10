#include <iostream>

using namespace std;

class Person{
    public:
    string name;
    int age;
   
};

class Employee:public Person{
    public:
    int employeeID;

   
};

class Manager:public Employee{
    public:
    string depInfo;

    

    void display(){
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Department Info: " << depInfo << endl;
    }
};

int main() {
    Manager mgr;
    mgr.name = "Alice";
    mgr.age = 35;
    mgr.employeeID = 12345;
    mgr.depInfo = "Sales";

    mgr.display();

    return 0;
}
 
