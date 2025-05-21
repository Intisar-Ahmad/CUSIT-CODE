#include<iostream>

using namespace std;

class Person{

public:
 string name;
 int age;
Person(string name,int age):name{name},age{age}{

}
};

class Prof:public Person{

public:
    string spec;
    Prof(string name,int age,string spec):Person(name,age),spec{spec}{}

    void display(){
        cout<<name<<endl<<age<<endl<<spec<<endl;
    }
};



int main(){
    Prof p1("bhino",19,"cs");
    p1.display();
    return 0;
}