#include <iostream>

using namespace std;

class Greet
{

public:
    // runtime
   virtual void greet(){
        cout << "greet" << endl;
    }

};

class muslimGreet:public Greet{
    public:
    void greet() override{
        cout << "salam" << endl;
    }
};

int main() {
   muslimGreet m;
// m.greet();
   Greet* ptr;
   ptr = &m;
   ptr->greet();
    return 0;
}