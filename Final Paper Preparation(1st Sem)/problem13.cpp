#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    //initialize a structure without using the . operator
    Person p1 = {"Bhino", 19};  // Shortcut initialization
    //The initializing must be in sequence
    cout << p1.name << " " << p1.age << endl;
    return 0;
}