#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class person   
{
private:
    string name;
    int age;
    float height;
   
public:
    person(string name,int age, float height){
        cout<<"This is the main constructor"<<endl;
        setName(name);
        setAge(age);
        this->height = height;
    }

    //getters are used to control the access of a private member
    string getName(){
        return name;
    }

    //setters are used to set private members of a class
    void setName(string name){
        //logic
        this->name = name;
    }

    //Now lets say i want to manipulate the age of a person so that it always stay 18
    void setAge(int age){
        this->age = 18;
        // now no matter what age will always be 18
    }
    void display(){
        cout<<this->name<<endl;
        cout<<this->age<<endl;
        cout<<this->height<<endl;
    }


};



int main(){
    person per("Bhino",10,5.10);
    cout<<per.getName()<<endl;
    // per.display();
    return 0;
}