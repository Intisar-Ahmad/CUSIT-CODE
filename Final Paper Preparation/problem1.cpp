#include<iostream>

using namespace std;

int main(){

    //How to find the second largest number in an array
    int arr[10] = {9,6,4,7,3,6,8,1,0,5};
    int maxNumber = 0;//Initialize with the lowest numbr possible
    int secMax = 0;//Same here
    for (int i = 0; i < 10; i++)
    {
        if(arr[i] > maxNumber){//Check if arr[i] is greater than the maxNumber
            secMax = maxNumber;//If true assign the value of the previous largest Number to secMax
            maxNumber = arr[i];//Update the maxNumber
        }
    }
    //You can ask chatGPT for further explanation
    cout<<secMax<<maxNumber<<endl;
    return 0;
}