#include <iostream>

using namespace std;
int main()
{
    // pyramind pattern
    /*  *
       ***
      *****
     ******* */
    int n ;// I declared n which will be the number of * on the final line if its odd and n-1 * if it is even
    cout<<"Please enter a positive number:";
    cin>>n;
    if(n<=0){//This is an edge case in which the user may enter a value other than a positive number
        cout<<"Invalid Input"<<endl;
        return 0;
    }
     
    int spaces = n / 2;// And spaces which is n/2 which I will decrement after every iteration
    //As we know that for the pyramid the number of spaces before the * after every line decreases
    for (int i = 1; i <= n; i += 2) //This is the outer loop which will responsible for the number of lines and number of * printed. The increment with 2 is crucial for the pyramid shape otherwise the shape will be different and the logic won't work. However much the value of n is the number of lines will be its half and if the value is floating point it will be rounded up.e.g if n = 3 the number of lines will be 2 and spaces in the first line will be 1.
    {
        for (int j = 1; j <= spaces; j++)//This loop is for printing the spaces before the *.
        {
            cout << " ";
        }
        for (int j = 1; j <= i; j++)//This will actually print the *
        {
            cout << "*";
        }
        cout << endl;//This step is important as for the pyramid shape new lines are necessary
        spaces--;//decrements the spaces variable by 1.
    }
    return 0;
}
