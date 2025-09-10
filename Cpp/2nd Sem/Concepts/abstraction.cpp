#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class greeting//this is now an abstract class
{
private:
    string accountNumber;
    float balance;

public:
    //pure virtual function
    virtual void display() = 0;
    virtual void hi() = 0;
    virtual void bye() = 0;

    void greet(){
        display();
        hi();
        bye();
    }



    greeting(string accountNumber, float balance)
    {
        cout << "this is constructor" << endl;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }
};

int main()
{
    // an object of an abstract class is not allowed
    // greeting act("fsklflskjdfiosldf", 400000);

    return 0;
}