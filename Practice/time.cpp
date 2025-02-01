#include<iostream>

using namespace std;

int main(){
    int time ;
    cout<<"please enter 1 if the student arrived from 12:00pm to 12:15pm"<<endl;
    cout<<"please enter 2 if the student arrived at 12:16pm"<<endl;
    cout<<"please enter 3 if the student arrived at 12:17 or later"<<endl;
    cin>>time;  
    switch (time)
    {
    case 1:
    {
        cout<<"STUDENT CAN BE ALLOWED"<<endl;
        break;
        }
    case 2:
    {
        cout<<"STUDENT CAN BE EXCUSED"<<endl;
        break;
    }
    case 3:
    {
        cout<<"Student is not allowed"<<endl;
        break;
    }

    default:
    cout<<"invalid Input"<<endl;
        break;
    }
    return 0;
}