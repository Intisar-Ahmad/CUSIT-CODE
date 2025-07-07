#include <iostream>

using namespace std;

class X{
    public:
    int a;
    // implement minus operator
    X operator-(X obj){
        X temp;
        temp.a = this->a - obj.a;
        return temp;
    }
};

int main() {
    X a,b,c;
    a.a = 2;
    b.a = 7;

    c = a - b;

    cout << c.a << endl;

    return 0;
}