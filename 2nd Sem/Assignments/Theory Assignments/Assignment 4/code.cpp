#include <iostream>
using namespace std;

// Function template
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Integer examples
    int x = 10, y = 20;
    cout << "Max(int): " << findMax(x, y) << endl;

    // Float examples
    float a = 5.5f, b = 3.3f;
    cout << "Max(float): " << findMax(a, b) << endl;

    // Char examples
    char ch1 = 'A', ch2 = 'Z';
    cout << "Max(char): " << findMax(ch1, ch2) << endl;

    char ch3 = 'k', ch4 = 'g';
    cout << "Max(char): " << findMax(ch3, ch4) << endl;

    // Another float example
    float c = 7.25f, d = 7.26f;
    cout << "Max(float): " << findMax(c, d) << endl;

    // Another int example
    int p = -5, q = -10;
    cout << "Max(int): " << findMax(p, q) << endl;

    return 0;
}
