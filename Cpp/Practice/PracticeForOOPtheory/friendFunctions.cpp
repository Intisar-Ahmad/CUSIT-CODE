#include <iostream>

using namespace std;

class A{

private:
 int x = 10,y = 7;

 friend void show(A o);
};



void show(A obj){
cout<<obj.x<<endl;
}

int main() {
    A obj;
    show(obj);
    return 0;
}