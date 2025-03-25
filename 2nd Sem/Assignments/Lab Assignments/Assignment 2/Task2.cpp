#include <iostream>
using namespace std;
/*
Task 2: Create a class StudentRecord with the following
attributes:
• Id
• name
• grade
• department
• contactNumber
Requirements:
1. Use a parameterized constructor to initialize all attributes when creating an object.
2. Implement a method displayRecord(); to print the student's record.
*/

class StudentRecord {
private:
    int Id;
    string name;
    char grade;
    string department;
    string contactNumber;

public:
    // Parameterized constructor to initialize all attributes
    StudentRecord(int id, string n, char g, string dept, string contact)
        : Id(id), name(n), grade(g), department(dept), contactNumber(contact) {}

    // Method to display student record
    void displayRecord() {
        cout << "Student ID: " << Id << endl;
        cout << "Name: " << name << endl;
        cout << "Grade: " << grade << endl;
        cout << "Department: " << department << endl;
        cout << "Contact Number: " << contactNumber << endl;
    }
};

int main() {
    StudentRecord student1(16880, "Intisar Ahmad", 'A', "Computer Science", "0333-333-3333");
    student1.displayRecord();

    return 0;
}
