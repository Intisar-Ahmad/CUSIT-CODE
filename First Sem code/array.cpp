#include<iostream>

using namespace std;

int main(){
    int marks[5] = {100,200,345,234,125};
    for (int i = 0; i < 5; i++)
    {
        cout<<"Student "<<i+1<<" "<<marks[i]<<endl;
    }
    
    return 0;
}