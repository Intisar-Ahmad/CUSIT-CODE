#include <iostream>

using namespace std;
//pure virtual functions


//abstract classes

//1. can't be instantiated
//2. must be inherited

class A{
    public:
    int x;
    int y;

    void greet(){
        cout << "hello" << endl;
    }
    //pure virtual function
    virtual void func() = 0;
    virtual void func1() = 0;
};

class B:public A{
    public:
    void func(){
        cout << "function is functioning" << endl;
    }
    void func1(){
        cout << "function is functioning" << endl;
    }
};

int main() {
   B obj;

//    A ob; // no no

// A *obj; yes yes
    return 0;
}