#include <iostream>

using namespace std;

// Q# 3: Given the array int array [] = {301, 302, 303, 301, 305, 303, 304,
// 299, 333, 305, 312, 315, 305} find and remove all the duplicate
// elements from the array.


int main() {
    
    int array [] = {301, 302, 303, 301, 305, 303, 304, 299, 333, 305, 312, 315, 305};
    int size = 13;
    int newSize = 0;
    int uniqueNumbers[13];

    for (int i = 0; i < size; i++)
    {
        int count = 0;

        for (int j = 0; j < size; j++)
        {

            if(array[i] == array[j]){
                count++;
            }
        }
        

        if(count == 1){
            uniqueNumbers[newSize] = array[i];
            newSize++;
        }

    }
    
 
    for (int i = 0;i<newSize;i++)
    {
        cout<< uniqueNumbers[i] << " ";
    }
    cout<< endl;
    
    return 0;
}