#include <iostream>

using namespace std;
// addition for a complex number
class complexNumber
{
public: // real + imaginary // a + bi
    float real;
    float imaginary;

    complexNumber(float r = 0, float i = 0)
    {
        real = r;
        imaginary = i;
    }

    // operating overloading
    complexNumber operator-(const complexNumber &c)
    {
        complexNumber temp;
        temp.real = this->real + c.real;
        temp.imaginary = this->imaginary + c.imaginary;
        return temp;
    }

    //   complexNumber operator-(const complexNumber &c){
    // do this one yourself
    //   }

  


};

int main()
{
    complexNumber c1(2, 3);
    complexNumber c2(4, 5);
    complexNumber c3 = c1 - c2;

    return 0;
}