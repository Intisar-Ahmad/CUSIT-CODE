#include<iostream>

using namespace std;

int main(){
    // Reverse an array in-place using a loop (without using extra space). This means don't initialize another array or variable
    int arr[10] = {9,6,4,7,3,6,8,1,0,5};
    int low = 0;
    int high = 9;
    while(low<=high){
        // '^' is the bitwise XOR operator
        // arr[low] = arr[low] ^ arr[high];
        // arr[high] = arr[low] ^ arr[high];
        // arr[low] = arr[low] ^ arr[high];

        // you can use the code down below which is commented
        // arr[low] = arr[high] - arr[low];//This is also the logic to swap two numbers
        // arr[high] = arr[high] - arr[low];
        // arr[low] = arr[high] + arr[low];

        //You can also use the swap method
        swap(arr[low],arr[high]);
        low++;
        high--;
    }
    for (int i = 0; i < 10; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}