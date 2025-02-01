#include<iostream>

using namespace std;

int main(){
    int ages[3] = {15,28,30};
    int sum = 0;
for (int i = 0; i < 3; i++)
{
    // sum = sum + ages[i];
    sum+=ages[i];
    cout<<sum<<endl;
}
cout<<sum/3.0<<endl;
    return 0;
}