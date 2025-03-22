#include <iostream>

using namespace std;

/*
Create a class for height object that takes height in Feet and inches
with functions that can add and subtract two given heights accurately.

List of functions: setValue(), getValue(), addValue(), subtractValue().

Use constructor to initialize the values of the object
*/

class Height
{
private:
    int feet;
    int inches;

    void normalize()
    {
        if (inches >= 12)
        {
            feet += inches / 12;
            inches %= 12;
        }
        else if (inches < 0)
        {
            feet -= (-inches) / 12 + 1;
            inches = 12 - (-inches % 12);
        }
    }

public:
    // Constructor
    Height(int f = 0, int i = 0) : feet(f), inches(i)
    {
        normalize();
    }

    // Set height
    void setValue(int f, int i)
    {
        feet = f;
        inches = i;
        normalize();
    }

    // Get height
    void getValue()
    {
        cout << feet << " feet " << inches << " inches\n";
    }

    // Add two height objects
    Height addValue(const Height &h)
    {
        return Height(feet + h.feet, inches + h.inches);
    }

    // Subtract two height objects
    Height subtractValue(const Height &h)
    {
        return Height(feet - h.feet, inches - h.inches);
    }
};

int main()
{
    Height h1(5, 8), h2(3, 10);

    cout << "Height 1: ";
    h1.getValue();

    cout << "Height 2: ";
    h2.getValue();

    Height sum = h1.addValue(h2);
    cout << "Sum: ";
    sum.getValue();

    Height diff = h1.subtractValue(h2);
    cout << "Difference: ";
    diff.getValue();

    return 0;
}
