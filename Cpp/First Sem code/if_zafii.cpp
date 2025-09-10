#include <iostream>

using namespace std;
int main()
{
    int a;
    cin >> a;
    if (a > 100 && a < 1)
    {
        cout << "worng input";
    }
    if (a > 90 && a <= 100)
    {
        cout << "A+";
    }
    if (a > 80 && a <= 90)
    {
        cout << "A";
    }
    if (a > 70 && a <= 80)
    {
        cout << "B+";
    }

    return 0;
}