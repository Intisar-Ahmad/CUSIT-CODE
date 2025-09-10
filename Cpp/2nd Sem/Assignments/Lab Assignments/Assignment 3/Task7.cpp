//Fixing the code

#include <iostream>
using namespace std;
class Book {
string title;
int year;
public:
Book(string t, int y) {
title = t;
year = y;
}
void display() {
cout << "Title: " << title << endl;
cout << "Year: " << year << endl;
}
};
int main() {
Book b1("C++ Programming", 2021);
b1.display();
// Book b2; this doesn't work because there is no unparameterized constructor o default constructor in the class
//fix
Book b2("Python Programming", 2022); // creating an object using the parameterized constructor
b2.display();
return 0;
}