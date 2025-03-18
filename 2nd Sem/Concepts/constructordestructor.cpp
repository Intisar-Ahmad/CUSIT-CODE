#include<iostream>

using namespace std;

class person
{
public:
    string* name;
    int age;
    float height;

    //default constructor
    // person(){
    //     cout<<"This is a constructor"<<endl;
    //     name = "Intisar";
    //     age = 54;
    //     height = 5.10;
    // }
    //parameterized constructor
    person(string name,int age, float height){
        cout<<"This is a parameterized constructor"<<endl;
        this->name = new string(name);
        this->age = age;
        this->height = height;
    }

    //copy constructor
    person(person& other){
        cout<<"This is a copy constructor"<<endl;
        name = new string(*(other.name));// deep copy
        age = other.age;
        height = other.height;
    }


    //destructor
    ~person(){
        delete name;
        cout<<"Destructor Called"<<endl;
    }
    void display(){
        cout<<this->name<<endl;
        cout<<*(this->name)<<endl;
        cout<<this->age<<endl;
        cout<<this->height<<endl;
    }

};



int main(){
    // person p1; default constructor
    // person p1("Bhino",19,5.10); parameterized constructor
    person p1("Bhino",19,5.10);
    person p2 = p1;
    p1.display();
    p2.display();
    return 0;
}