 #include<iostream>
 
 using namespace std;
 
    /*
    Task 2: Create a class Animal with the following
attributes:
• name
• color
• breeder
• weight
Requirements:
• Create 3 different Animal objects and assign values to their attributes.
• Print the attributes of each object.
    */

class Animal{
    public:
    string name;
    string color;
    string breeder;
    float weight;
    
    
    };


 int main(){

    Animal animal1;
    animal1.name = "Cat";
    animal1.color = "White";
    animal1.breeder = "Breeder1";
    animal1.weight = 5.2;  


    Animal animal2;
    animal2.name = "Dog";
    animal2.color = "Black";
    animal2.breeder = "Breeder2";
    animal2.weight = 10.74;


    Animal animal3;
    animal3.name = "Parrot";
    animal3.color = "Green";
    animal3.breeder = "Breeder3";
    animal3.weight = 2.1;

    cout << "Name: " << animal1.name << endl;
    cout << "Color: " << animal1.color << endl;
    cout << "Breeder: " << animal1.breeder << endl;
    cout << "Weight: " << animal1.weight << "kg" << endl;

    cout<<endl;

    cout << "Name: " << animal2.name << endl;
    cout << "Color: " << animal2.color << endl;
    cout << "Breeder: " << animal2.breeder << endl;
    cout << "Weight: " << animal2.weight << "kg" << endl;

    cout<<endl;

    cout << "Name: " << animal3.name << endl;
    cout << "Color: " << animal3.color << endl;
    cout << "Breeder: " << animal3.breeder << endl;
    cout << "Weight: " << animal3.weight << "kg" << endl;
    return 0;
 }