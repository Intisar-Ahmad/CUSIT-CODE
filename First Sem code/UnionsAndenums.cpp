#include<iostream>
#include<vector>

using namespace std;

union money
{
 int rice;
 int mangoes;
};//You can access only one union element at a time

enum Meal{
breakfast = 1,
lunch = 2,
dinner = 3
};
int main(){
    money m1; m1.rice = 100;
    m1.mangoes = 10;
    cout<<m1.mangoes<<endl<<m1.rice;//this will only print 10 twice since m1.rice has been overwritten.
    Meal M = dinner;
    cout<<M;
    
    return 0;
}