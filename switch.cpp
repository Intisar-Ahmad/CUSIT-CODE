#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main(){
    int age = 5;
    switch (age)
    {
    // case (age>=5 && age<=20): not possible
        cout<<"You are a stud";
        break;
    
    default:
        break;
    }
    return 0;
}