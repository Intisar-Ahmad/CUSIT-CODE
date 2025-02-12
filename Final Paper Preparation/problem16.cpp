#include<iostream>

using namespace std;

int main(){
    //Given an integer, reverse its digits without converting it to a string.

    int n = 9034;
    int reverse = 0;
    while(n!=0){
        reverse = (reverse * 10) + (n%10);
        n/=10;
    }
    cout<<reverse<<endl;
    return 0;
}