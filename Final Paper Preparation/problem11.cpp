#include<iostream>

using namespace std;


int reverse(int n){
    cout<<n<<" ";
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    return reverse(n-1);
}


void reverse2(int n){//This also another way doing this
    cout<<n<<" ";
    if(n == 0){
        return ;
    }
    if(n == 1){
        return ;
    }
     reverse(n-1);
}

int main(){
    // Given N, print numbers from N to 1 using recursion
    int n= 10;
    reverse(n);

    return 0;
}