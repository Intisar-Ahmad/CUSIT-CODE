#include <iostream>

using namespace std;

/*
Task 1: Create a class Car with the following
attributes:
• brand
• model
• year
Requirements:
• Create 3 different Car objects and assign values to their attributes.
• Print the attributes of each object.
*/

class Car
{
public:
    string brand;
    string model;
    int year;
};

int main()
{
    Car car1;
    car1.brand = "Toyota";
    car1.model = "Corolla";
    car1.year = 2019;

    Car car2;
    car2.brand = "Honda";
    car2.model = "Civic";
    car2.year = 2018;

    Car car3;
    car3.brand = "Suzuki";
    car3.model = "Mehran";
    car3.year = 2017;

    cout << "Brand: " << car1.brand << endl;
    cout << "Model: " << car1.model << endl;
    cout << "Year: " << car1.year << endl;

    cout << endl;

    cout << "Brand: " << car2.brand << endl;
    cout << "Model: " << car2.model << endl;
    cout << "Year: " << car2.year << endl;

    cout << endl;

    cout << "Brand: " << car3.brand << endl;
    cout << "Model: " << car3.model << endl;
    cout << "Year: " << car3.year << endl;

    cout << endl;

    return 0;
}