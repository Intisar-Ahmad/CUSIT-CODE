#include<iostream>

using namespace std;

// Can be seperate functions
void MaxMin(int *arr){//This is to prove that arrays are pointers
    //And now you can directly access all the elements of the array if you know the length
    int Max = arr[0];
    int Min = arr[0];
    for(int i = 1;i<5;i++){
        if(arr[i] > Max){
            Max = arr[i];
        }else if(arr[i] < Min){
            Min = arr[i];
        }
    }
    cout<<Max<<" "<<Min<<endl;
}

int main(){
    //Write a function that takes an array and returns both the maximum and minimum elements.

    int arr[5] = {3,7,1,9,2};
    MaxMin(arr);
    return 0;
}