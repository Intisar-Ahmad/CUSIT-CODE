/*
Task 3: Constructor Overloading
1. Add another constructor to the same Person class that only takes a string name.
2. Now your class should have two constructors:
   • One that takes just a name
   • One that takes both name and age
3. Inside each constructor, print different messages to show which constructor is being used.
4. In main(), create two objects:
   • One using the constructor with only the name
   • One using the constructor with name and age
*/

#include <iostream>
using namespace std;

class Person {
public:
    // Default constructor
    Person() {
        cout << "Default constructor called" << endl;
    }

    // Constructor with only name
    Person(string name) {
        cout << "Constructor with name called" << endl;
        cout << "Name: " << name << endl;
    }

    // Constructor with name and age
    Person(string name, int age) {
        cout << "Constructor with name and age called" << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Person p1("Bhino");              
    Person p2("Bhino1", 19);        
    return 0;
}
