#include<iostream>

using namespace std;

int main(){

    //How to find the second largest number in an array
    int arr[5] = {9,6,4,7,3};
    int maxNumber = 0;//Initialize with the lowest numbr possible
    int secMax = 0;//Same here
    for (int i = 0; i < 5; i++)
    {

        // max = 9

        if(arr[i] > maxNumber){//Check if arr[i] is greater than the maxNumber
            secMax = maxNumber;//If true assign the value of the previous largest Number to secMax
            maxNumber = arr[i];//Update the maxNumber
        }
       else if(arr[i] > secMax && arr[i] < maxNumber){
            secMax = arr[i];
        }
    }
    //You can ask chatGPT for further explanation
    cout<<"Second Largest "<<secMax<<" Largest "<<maxNumber<<endl;
    return 0;
}