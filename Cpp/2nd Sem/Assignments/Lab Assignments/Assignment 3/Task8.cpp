/*
Task 8: What is the static Keyword? In your own words, explain what the
static keyword does. How does it affect the behavior of variables or
functions in a program?

1. Create a class named Counter.
2. Inside the class, declare a static integer variable called count.
3. In the constructor, increment the count every time a new Counter object is
   created.
4. Add a static function named getCount() that returns the value of count.
5. In your main() function:
   • Create 3 objects of the Counter class.
   • Call getCount() to print the total number of objects created.

Why would you use the static keyword here? Explain how the static
variable behaves differently from regular variables.
*/

#include <iostream>
using namespace std;

class Counter {
    static int count; // static variable shared by all objects

public:
    // Constructor
    Counter() {
        count++;
    }

    // Static function to get the value of count
    static int getCount() {
        return count;
    }
};

// Initialize the static variable outside the class
int Counter::count = 0;

int main() {
    Counter c1, c2, c3; // 3 objects created
    cout << "Total objects created: " << Counter::getCount() << endl;
    return 0;
}
