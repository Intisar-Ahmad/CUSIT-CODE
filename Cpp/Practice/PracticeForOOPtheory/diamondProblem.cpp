#include <iostream>

using namespace std;

class A{
    public:
    int x;
};

class B:virtual public A{
    //definition
};//virtual inheritance

class C:virtual public A{
};

class D:public B, public C{
    public:

};

int main() {
    D obj;
    obj.x = 10;
    return 0;
}