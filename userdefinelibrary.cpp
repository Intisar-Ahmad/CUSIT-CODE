#include<iostream>
using namespace std;
#include<cstring>
#include<vector>
#ifndef MYLIB
#define MYLIB

//Function declaration
void greet(){
    cout<<"Hello\n";
}
int add(int a,int b){
    cout<<"Addition:"<<a+b<<endl;
    return a+b;
}

int global = 56;
#endif

#define/*directive*/ pi/*Macro Name*/ 3.14/*Macro replacement*/

int main(){
    greet();
    add(2,3);

    cout<<pi<<endl;
    cout<<global<<endl;

    string str = "Harry";
    string str2;
    for (int i = 0; i < str.length(); i++)
    {
        cout<<str[i]<<endl;
    }
    // strcpy(str2,str);
    
    return 0;
}