#include<iostream>

using namespace std;

class Employee{
    public:
    string name;
    int age;
    int yearsOfExperience;
};

class Engineer:public Employee{
    public:
    string techStack;

    void displayEngineerInfo(){
        cout<<name<<endl;
        cout<<age<<endl;
        cout<<yearsOfExperience<<endl;
        cout<<techStack<<endl;
    }
};

int main(){
    Engineer e1;
    e1.name = "Bhino";
    e1.age = 19;
    e1.yearsOfExperience = 1;
    e1.techStack = "MERN";


    e1.displayEngineerInfo();
    return 0;
}