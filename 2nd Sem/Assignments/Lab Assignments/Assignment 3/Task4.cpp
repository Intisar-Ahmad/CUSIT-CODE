/*
Task 4: Copy Constructor
1. Add a copy constructor to the Person class.
2. Inside the constructor, copy the name and age values from the passed object.
3. Also, print:
   "Copy constructor called"
4. In main(), first create a Person object using the parameterized constructor,
   then create another object by copying the first one.
*/

#include <iostream>
using namespace std;

class Person {
    string name;
    int age;

public:
    // Default constructor
    Person() {
        cout << "Default constructor called" << endl;
    }

    // Constructor with only name
    Person(string n) {
        name = n;
        age = 0;
        cout << "Constructor with name called" << endl;
        cout << "Name: " << name << endl;
    }

    // Constructor with name and age
    Person(string n, int a) {
        name = n;
        age = a;
        cout << "Constructor with name and age called" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    // Copy constructor
    Person(const Person &p) {
        name = p.name;
        age = p.age;
        cout << "Copy constructor called" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Person p1("Bhino", 40);  
    Person p2 = p1;            
    return 0;
}
