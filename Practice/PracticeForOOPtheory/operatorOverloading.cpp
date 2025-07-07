#include <iostream>

using namespace std;

class A
{
public:
    int x = 10;

    void operator+(int b)
    {
        cout << this->x + b << endl;
    }

    void display()
    {
        this->x;
        cout << "bhino" << endl;
    }
};

// a + bi 5 + 8i  ---> 11 + 11i ans
// x + yi  6 + 3i



class complex
{
public:
    float real, imaginary;

    complex(float r, float i)
    {
        real = r;
        imaginary = i;
        cout << real << "+" << imaginary << "i" << endl;
    }

    void operator+(complex c)
    {
        cout << this->real + c.real << "+" << this->imaginary + c.imaginary << "i" << endl;
       
    }

    void operator==(complex c)
    {
        // r == r , i == i
        if (this->real == c.real && this->imaginary == c.imaginary)
        {
            cout << "equal" << endl;
            return;
        }
        cout << "not equal" << endl;
    }
};

int main()
{
    // int x = 10, y = 11;
    // A a,b;
    // a.display();
    // a.operator+(5);
    // a+5;

    // x+y;

    complex c1(3, 6);
    complex c2(3, 6);

    c1 + c2;
    c1 == c2;
    // r + r , i + i



    return 0;
}