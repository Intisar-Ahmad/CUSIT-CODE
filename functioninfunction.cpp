#include<iostream>

using namespace std;

int print(){
    cout<<"This is me"<<endl;return 5;
}

int add(){
    print();
}


int main(){
    add();
    return 0;
}