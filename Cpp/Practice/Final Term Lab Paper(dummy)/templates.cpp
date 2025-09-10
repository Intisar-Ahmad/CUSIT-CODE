#include <iostream>

using namespace std;

template <typename T>
void iswap(T num1, T num2)
{
    T temp = num1;
    num1 = num2;
    num2 = temp;
    cout << "Swapped values: " << num1 << " and " << num2 << endl;
}

template <typename T, typename G>

void multi(T a, T b, T c , G d){
    cout << a * b * c * d;
}



int main()
{
    int x = 2,y = 3;
    iswap(x, y);
    iswap('a', 'b');
    iswap(2.5, 3.5);
    iswap("Hello", "World");

    // multi(3.5,4.5,5.1,6);



    return 0;
}