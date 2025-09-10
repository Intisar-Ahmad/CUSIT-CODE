#include <iostream>

using namespace std;


template<typename T>
T add(T a, T b){
    return a + b;
}
template<typename T>
T sub(T a, T b){
    return a - b;
}
template<typename T>
T multi(T a, T b){
    return a * b;
}
template<typename T>
T divide(T a, T b){
    if(b == 0){
        cout << " Division not possible" << endl;
        return a;
    }
    return a / b;
}



int main() {
    int a = 6, b = 7;
    float x = 6.5, y = 7.5;
    char c = 'A', d = 'B';

    
    cout << "Integer Addition: " << add(a, b) << endl;
    cout << "Integer Subtraction: " << sub(a, b) << endl;
    cout << "Integer Multiplication: " << multi(a, b) << endl;
    cout << "Integer Division: " << divide(a, b) << endl;

    cout << "Float Addition: " << add(x, y) << endl;
    cout << "Float Subtraction: " << sub(x, y) << endl;
    cout << "Float Multiplication: " << multi(x, y) << endl;
    cout << "Float Division: " << divide(x, y) << endl;

    cout << "Char Addition: " << add(c, d) << endl;
    cout << "Char Subtraction: " << sub(c, d) << endl;
    cout << "Char Multiplication: " << multi(c, d) << endl;
    cout << "Char Division: " << divide(c, d) << endl;

    return 0;
}