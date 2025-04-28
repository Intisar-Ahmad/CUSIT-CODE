#include<iostream>

using namespace std;

class complex{
    public:                                                
    float real{0};
    float imag{0};//a+bi

    complex(float real,float imag):real{real},imag{imag}{
       
    };

    // operator overloading
   void operator+(complex &c){
    //logic
    cout<<"i am adding\n";
    cout<<real<<" + "<<imag<<"i"<<" + "<<c.real<<" + "<<c.imag<<"i"<<" = "<<real+c.real<<" + "<<imag+c.imag<<"i"<<endl;
   }


    void display(){
        cout<<real<<" + "<<imag<<"i"<<endl;
    }

};

int main(){
    complex c1(2.0,3.0);
    complex c2(1.5,7.1);
    c1.display();
    c2.display();
    
   c1.real = c1.real + c2.real;

   c1 + c2;

    return 0;
}