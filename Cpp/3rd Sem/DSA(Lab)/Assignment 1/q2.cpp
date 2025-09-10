#include <iostream>

using namespace std;

//Q# 2: Given the array int orderIds [] = {201, 202, 203, 204, 205}
// contains customer orders. Remove the id 202 and shift the elements.

int main() {
    int orderIds [] = {201, 202, 203, 204, 205};

    for (int i = 1; i < 4; i++)
    {
       orderIds[i] = orderIds[i+1];
    
    }
    
    for (int i = 0; i < 4; i++)
    {
        cout << orderIds[i] << endl;
    }
    

    return 0;
}