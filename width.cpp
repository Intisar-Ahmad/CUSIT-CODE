#include<iostream>

using namespace std;
int main(){
    int length,width;
    cout<<"Please enter the length of the room(in meters):";
    cin>>length;
    cout<<"Please enter the width of the room(in meters):";
    cin>>width;
    if(width <= 0 || length <= 0){
        cout<<"Invalid Input"<<endl;
        return 0;
    }
    int area = length*width;
    cout<<"Total Area of the room : "<<area<<" Square Meters";
    return 0;
}