/*
Task 1: Default Constructor
1. Create a class named Person.
2. Inside the class, add a default constructor.
3. Inside the constructor, print this message:
   "Default constructor called"
4. In your main() function, create an object of the Person class using the
   default constructor.
*/

#include <iostream>
using namespace std;

class Person {

public:
    Person() {
        cout << "Default constructor called" << endl;
    }
};

int main() {
    Person p;
    return 0;
}
