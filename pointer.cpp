#include<iostream>

using namespace std;

int* func(){
    int x = 9;
    int* ptr = &x;
    return ptr;
}

int main(){
    int x = 5;
    int * ptr = func();
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
    cout<<&x<<endl;
    return 0;
}