#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class bhino
{
private:
   int marks;
   float GPA;
public:
  bhino(int marks):marks(marks),GPA(marks/100.0){}

  void display(){
    cout<<marks<<endl;
    cout<<GPA<<endl;
  }

  friend bool compareMarks(const bhino &p1,const bhino &p2);
};

bool compareMarks(const bhino &p1,const bhino &p2){
return p1.marks > p2.marks ;
    
}

int main(){
    bhino p1(400);
    bhino p2(357);
    p1.display();
    p2.display();
    cout<<compareMarks(p1,p2);
    return 0;
}