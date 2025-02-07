#include<iostream>
#include<iomanip>

using namespace std;
int main(){
    int birthdayItems = 15.0;
    float price = 4.0;
    float totalPrice = price * birthdayItems;
    cout<<fixed<<setprecision(2)<<"Total cost: $"<<totalPrice<<endl;
    return 0;
}