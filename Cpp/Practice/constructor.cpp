#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class student{
private:
   string name;
    int marks;
public:
    
    student(string n,int m){
        name = n;
        marks = m;
        //logic
    }

    void display(){
        cout<<name<<endl;
        cout<<marks<<endl;
    }
};

int main(){
    student student1("Intisar",67);
    student student2("Musa",0);
    student1.display();
    student2.display();
    return 0;
}