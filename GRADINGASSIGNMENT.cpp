#include<iostream>


using namespace std;
int main(){
    int marks;

    cout<<"Please enter your marks : ";
    cin>>marks;
    if(marks > 100){
        cout<<"Invalid Input\n";
        return 0;
    }
    if(marks >= 91 && marks <= 100){
    cout<<"Your grade is A+ because you scored "<<marks<<" marks out of 100"<<endl;
        
    }
    else if(marks >= 81 && marks <= 90){
    cout<<"Your grade is A because you scored "<<marks<<" marks out of 100"<<endl;
    
    }
    else if(marks >= 71 && marks <= 80 ){
    cout<<"Your grade is B+ because you scored "<<marks<<" marks out of 100"<<endl;
        
    }
     else if(marks >= 61 && marks <= 70){
    cout<<"Your grade is B because you scored "<<marks<<" marks out of 100"<<endl;
    
    }
    else if(marks >= 50 && marks <= 60){
    
    cout<<"Your grade is C because you scored "<<marks<<" marks out of 100"<<endl;
    }
    else{
        cout<<"You failed because your score is less than 50%"<<endl<<"Grade F";
    }
    return 0;
}