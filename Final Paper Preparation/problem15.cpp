#include<iostream>

using namespace std;

int main(){
    // sum of all the digits in an integer
    int n = 9041;
    int sum = 0;
  while(n!=0){
    sum+=n%10;
    n/=10;
  }
    cout<<sum<<endl;
    return 0;
}