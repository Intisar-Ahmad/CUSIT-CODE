//Fixing the error

#include <iostream>
using namespace std;
class Student {
string name;
int age;
public:
Student(string name, int age) {
this->name = name;//using the 'this' keyword allows the compilor to determine between function parameteers and actual member variables in the class
this->age = age;// without the 'this' keyword , the compiler only sees the function parameters and hence the garbade values
}
void display() {
cout << "Name: " << name << endl;
cout << "Age: " << age << endl;
}
};
int main() {
Student studentObj("Ali", 15);
studentObj.display();
return 0;
}