#include<iostream>

using namespace std;

int Factorial(int n){
        if(n == 0 || n == 1){//The factorial of 0 and 1 is 1
            return 1;
        }
        return n*Factorial(n-1);
}

int main(){
    //Finding Factorial using recursion
    int number = 5;
    cout<<Factorial(number)<<endl;
    return 0;
}