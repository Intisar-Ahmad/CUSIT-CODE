#include<iostream>

using namespace std;

int main(){
    //How to find length of an array
    int arr[8];//Lets assume you don't know the length of the Array
   
    int length = static_cast<int>(sizeof(arr)/sizeof(arr[0]));//this does not work in a function do not attempt to do it

    //sizeof(arr) gives the size of the whole array in the memory
    //sizeof(arr[0]) gives the size of the first element in the memory

    cout<<length<<" "<<endl;
    return 0;
}