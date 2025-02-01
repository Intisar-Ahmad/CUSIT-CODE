#include<iostream>

using namespace std;
struct structure
{
    int x;
    int y;
};
struct nestedStruct
{
    structure sd;
    string name;
};

int main(){
    nestedStruct p1;
    p1.sd.x = 1;
    p1.sd.y = 2;
    p1.name = "Bhino";
    cout<<p1.sd.x<<p1.sd.y<<p1.name<<endl;
    return 0;
}