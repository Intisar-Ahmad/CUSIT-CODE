#include <iostream>

using namespace std;

/*
Task 5: Create a class Person with the following
attributes:
• name
• age
• gender
Requirements:
• Gender must be either 'M' or 'F'. If an invalid value is provided, show error:
"Invalid Input! Only 'M' or 'F' allowed."
• Age must be greater than 0. If an invalid value is provided, show error:
"Invalid Input! Age must be greater than 0."
*/

class Person
{
private:
    int age;
    char gender;
public:

    string name;

    void setGender(char g)
    {
        if (g == 'M' || g == 'F' || g == 'm' || g == 'f')
        {
            gender = g;
        }
        else
        {
            cout << "Invalid Input! Only 'M' or 'F' allowed." << endl;
        }
    }

    void setAge(int a)
    {
        if (a > 0)
        {
            age = a;
        }
        else
        {
            cout << "Invalid Input! Age must be greater than 0." << endl;
        }
    }


    int getAge()
    {
        return age;
    }


    char getGender()
    {
        return gender;
    }
};
int main()
{
    Person person1;
    person1.name = "Ali";
    person1.setGender('M');
    person1.setAge(-1);

    // cout << "Name: " << person1.name << endl
    //      << "Age: " << person1.getAge() << endl
    //      << "Gender: " << person1.getGender() << endl;
    return 0;
}