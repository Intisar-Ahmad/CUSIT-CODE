#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class person{
    public:
    string name;
    int age;
    float height;
    //default constructor
    // person(){

    // }
    //parameterized constructor
    person(string name,int age,float height){
        cout<<"this is a constructor"<<endl;
        this->name = name;
        this->age = age;
        this->height = height;
    }
    //unparameterized 
    person(){
        cout<<"This is an  unparameterized constructor"<<endl;
    }

    //destructor



    void display(){
        cout<<this->name<<endl;
        cout<<age<<endl;
        cout<<height<<endl;
    }
};

void i(){
    int x = 0;
}

int main(){
    person obj;
    // obj.display();
    return 0;
}