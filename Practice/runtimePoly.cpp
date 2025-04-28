#include <iostream>
using namespace std;

class Base {
public:
   virtual void display() {
        cout << "Base display\n";
    }
};

class Derived : public Base {
public:
    void display() {
        cout << "Derived display\n";
    }
};

int main() {// for this to run expectedly , we must use the virtual keyword in the base class 
    Base* b;
    Derived d;
    b = &d;
    b->display();
    (*b).display();
    return 0;
}
