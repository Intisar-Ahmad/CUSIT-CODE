#include<iostream>

using namespace std;

class BankAcc
{
private:
    double balance;

public:
    BankAcc(double b);
   
    double withDraw(double amount){
        if(amount < 0){
            cout<<"Invalid amount"<<endl;
        }
        else if(amount > balance){
            cout<<"Insufficient balance"<<endl;
        }
        else{
            balance -= amount;
            return amount;
        }
        return 0.0;
    }

};

BankAcc::BankAcc(double b)
{
    balance = b;
}



int main(){
    
BankAcc some(1000);

cout<<some.withDraw(200)<<endl;
cout<<some.withDraw(-9)<<endl;
cout<<some.withDraw(90000)<<endl;
    return 0;
}