#include <iostream>

using namespace std;

class Payment
{
public:
     void processPayment()
    {
        cout << "original"<<endl;
    }
};

class CCPayment : public Payment
{
public:
  void processPayment()
    {
           cout << "CCpayment" <<endl;
    }


};

class PPPayment : public Payment
{
public:
  void processPayment()
    {
        cout << "PPpayment" <<endl;
    }
};

int main()
{
    Payment *ptr1 = new CCPayment();
    Payment *ptr2 = new PPPayment();

    (*ptr1).processPayment();
    ptr2->processPayment();


    return 0;
}