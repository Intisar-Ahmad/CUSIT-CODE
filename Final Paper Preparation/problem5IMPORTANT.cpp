#include<iostream>

using namespace std;

void Swap(int &n1,int &n2){//we will use the '^' XOR operator for this function
    n1 = n1 ^ n2;
    n2 = n1 ^ n2;
    n1 = n1 ^ n2;
}

int main(){
    //Functions: Implement a function that swaps two integers using call by reference (without using a third variable).
    int a = 5,b=6;
    Swap(a,b);
     
     //Try this function with various values
     cout<<a<<b<<endl;

    return 0;
}