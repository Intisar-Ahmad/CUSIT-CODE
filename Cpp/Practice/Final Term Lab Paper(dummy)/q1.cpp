#include <iostream>

using namespace std;





class Student{
    private:
    int marks;
    string name;

    public: 
    Student( string n, int m): marks(m), name(n){}

    friend void checkStudentResult();
    friend int main();

};

void checkStudentResult(){
    Student s1("bhino",95);

    if(s1.marks >= 90){
        cout << "Pass" << endl;
    }
    else {
        cout << "Fail" << endl;
    }
}



int main() {

 
    checkStudentResult();
    return 0;
}