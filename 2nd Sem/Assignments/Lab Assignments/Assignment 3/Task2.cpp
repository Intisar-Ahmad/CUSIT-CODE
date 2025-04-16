/*
Task 2: Parameterized Constructor
1. Add a parameterized constructor to the Person class.
2. The constructor should take two parameters:
   string name and int age.
3. Print the name and age values inside the constructor.
4. In main(), create a new object of Person using this constructor by passing a
   name and an age.
*/

#include <iostream>
using namespace std;

class Person {
    private:
    string name;
    int age;
public:
    // Default constructor
    Person() {
        cout << "Default constructor called" << endl;
    }

    // Parameterized constructor
    Person(string name, int age) {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Person p1;                   
    Person p2("Bhino", 19);       
    return 0;
}
