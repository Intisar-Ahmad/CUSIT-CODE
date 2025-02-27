#include<iostream>

using namespace std;

int* makeArray(int cups){
   int* arr = new int[cups];
   for (int i = 0; i < cups; i++)
   {
    arr[i] = i+1;
   }
   return arr;
}

int main(){
    int cups = 5;
    int *ptr = makeArray(cups);
    for (int  i = 0; i < cups; i++)
    {
        cout<<ptr[i]<<" ";
    }
    delete[] ptr;
    return 0;
}