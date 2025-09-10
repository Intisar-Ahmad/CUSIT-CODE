#include <iostream>
using namespace std;

template <typename T>
T sumValues(T a, T b) {
    return a + b;
}

int main() {
    cout << sumValues<int>(5, 5) << endl;        // Output: 10
    cout << sumValues<double>(2.5, 5.5) << endl; // Output: 8
    return 0;
}