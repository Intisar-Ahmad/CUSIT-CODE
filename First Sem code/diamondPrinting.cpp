#include <iostream>
using namespace std;

int main() {
    int n; // n will be the size of the diamond's widest point and must be odd as for even numbers the shape will look less symmetrical


    cout << "Enter a number for the size of the diamond: ";
    cin >> n;

    // Edge case to check if the number is odd and postive
    if (n <= 0 ) {
        cout << "Please enter a positive number." << endl;
        return 0;
    }

    int spaces = n / 2;  // Initial spaces before the first star in the upper half
   
    for (int i = 1; i <= n; i += 2) {//this outerloop prints the upper half of the diamond
        for (int j = 0; j < spaces; j++) {//thid loop id for the inital spacings that are going to decrease over time
            cout << " ";
        }
 
        for (int j = 0; j < i; j++) {//this will print the * for a single line just like the pyramid
            cout << "*";
        }
        cout << endl;
        spaces--; // Decrease spaces as we go downwards
    }

    spaces = 1;  // We re-initialize the spaces variable to 1 for the lower half of the diamond

 
    for (int i = n - 1; i >= 1; i -= 2) {//this reverse loop is for the lower half
        for (int j = 0; j < spaces; j++) {//for spacings
            cout << " ";
        }
        for (int j = 0; j < i; j++) {//for *
            cout << "*";
        }
        cout << endl;
        spaces++; //this time we increase the spacings as we go downward
    }

    return 0;
}
