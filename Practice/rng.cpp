#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int main(){
    int randomNUmber;
     srand(time(0)) ;

     randomNUmber = (rand()  % (3 - 1 + 1)) + 1;
     cout<<randomNUmber<<endl;
    return 0;
}