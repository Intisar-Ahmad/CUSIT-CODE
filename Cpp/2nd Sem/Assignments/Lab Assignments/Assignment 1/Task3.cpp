#include<iostream>

using namespace std;

/*
Task 3: Create a class Student with the following
attributes:
• name
• rollNumber
Requirements:
• Implement a method displayStudentInfo() that prints student details.
• After assigning values to a Student object, call displayStudentInfo().
*/

class Student{
    public:
    string name;
    int rollNumber;

    void displayStudentInfo(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll Number: "<<rollNumber<<endl;
    }
};

int main(){
    Student student1;
    student1.name = "Intisar";
    student1.rollNumber = 16880;


    student1.displayStudentInfo();
    return 0;
}