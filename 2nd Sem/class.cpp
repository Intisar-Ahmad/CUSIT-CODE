#include<iostream>
#include<vector>
using namespace std;

// struct student{
//     string name;
//     int id;
//     float gpa;

//     void display(){
//         cout<<name<<endl;
//         cout<<id<<endl;
//         cout<<gpa<<endl;
//     }
// };

class student{
    public:
       string name;
        int id;
        float gpa;

    void display(){
        cout<<name<<endl;
        cout<<id<<endl;
        cout<<gpa<<endl;
    }
};

int main(){
    student x;
    x.name = "BHINO";
    x.id = 16880;
    x.gpa = 3.67;

    x.display();
    x.id = 16990;
    return 0;
}