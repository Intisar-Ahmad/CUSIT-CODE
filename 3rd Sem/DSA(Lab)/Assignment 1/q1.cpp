#include <iostream>
using namespace std;

//Q# 1: Given the array int studentIds[] = {101, 104, 105, 107, 109} insert
//the id 106 at index 3.

int main() {
    int studentIds[] = {101, 104, 105, 107, 109};
    

    int newStudendIds[6];
    for (int i = 0; i < 3; i++)
    {
        newStudendIds[i] = studentIds[i];
    }
    newStudendIds[3] = 106;

    for (int i = 4; i < 6; i++)
    {
        newStudendIds[i] = studentIds[i - 1];
    }
    
    for (int i = 0; i < 6; i++)
    {
        cout << newStudendIds[i] << " ";
    }

    cout<<endl;
    

return 0;
}