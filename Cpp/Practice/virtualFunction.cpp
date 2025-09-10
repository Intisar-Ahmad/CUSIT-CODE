#include <iostream>

using namespace std;

class A{
    public:
    virtual void show(){
        cout << "something is very weird about this class" << endl;
    }
};

class B :public A{
    public:
     void show() {
        cout << "now this is better" << endl;
    }
};


// pure virtual function example

class C {
    public:
    virtual void greet() = 0;// can't have objects
};

class D : public C {
    public:
    void greet() override{
        cout << "hello namaste salam etc whatever"<< endl;
    }
};

int main() {
    A a;
    B b;
    A* ptr = new B();
    a.show(); // calls A's show
    b.show(); // calls B's show
    ptr->show(); // calls B's show due to virtual function

    
    C* c = new D();
    c->greet(); // calls D's greet

    return 0;
}