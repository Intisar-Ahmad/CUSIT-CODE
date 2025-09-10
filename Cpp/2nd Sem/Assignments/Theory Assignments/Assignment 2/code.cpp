#include <iostream>
using namespace std;

/*
Write a C++ program that defines a class "Student" with attributes for name, rollNumber, and GPA. 
Implement a parameterized constructor to initialize these attributes when an object is created 
and a destructor to display a message when an object is destroyed. 
Include a member function displayInfo() to print the student’s details. 
The program should create at least two objects within a function to clearly demonstrate 
when constructors and destructors are called.
*/

class Student {
private:
    string name;
    int rollNumber;
    float GPA;

public:
    Student(string n, int r, float g) : name(n), rollNumber(r), GPA(g) {
        cout << "Student object created for " << name << endl;
    }

    ~Student() {
        cout << "Student object destroyed for " << name << endl;
    }

    void displayInfo() {
        cout << "Name: " << name << ", Roll Number: " << rollNumber << ", GPA: " << GPA << endl;
    }
};


int main() {
    Student s1("Intisar Ahmad", 16880, 4.0);
    Student s2("Bhino", 16880, 4.0);
    s1.displayInfo();
    s2.displayInfo();
    return 0;
}
