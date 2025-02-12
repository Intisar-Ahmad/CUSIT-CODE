#include<iostream>

using namespace std;

int main(){
    //Fibonacci series using iteration
    int n = 5;
    int prev = 1;
    int Ultraprev = 0;

    for (int i = 1; i <= n; i++)
    {
        cout<<Ultraprev<<" ";
        int current = prev+Ultraprev;
        Ultraprev = prev;
        prev = current;
    }
    
  

    return 0;
}