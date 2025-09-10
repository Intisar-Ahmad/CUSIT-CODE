#include<iostream>


using namespace std;
int main(){
    int adults,children;
    cout<<"Enter the number of adults: ";
    cin>>adults;
    cout<<"Enter the number of children: ";
    cin>>children;
    if(adults < 0 || children < 0 ){
        cout<<"Invalid Input"<<endl;
        return 0;
    }
    int adultticket = 12;
    int childticket = 8;
    int totalcost = (adults*adultticket) + (children*childticket);
    cout<<"Total cost: $"<<totalcost<<endl;
    return 0;
}