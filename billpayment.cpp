#include<iostream>

using namespace std;
int main(){
    float totalbill;
    int numberofpeople;
    cout<<"Enter the total bill :";
    cin>>totalbill;
    cout<<"Enter the number of people:";
    cin>>numberofpeople;
    if(numberofpeople <= 0){
        cout<<"Invalid Input"<<endl;
        return 0;
    }
    float billperPerson = totalbill/numberofpeople;
    cout<<"Each person needs to pay: $"<<billperPerson<<endl;
    return 0;
}