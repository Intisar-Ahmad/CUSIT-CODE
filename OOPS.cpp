 #include<iostream>
 #include<vector>
 
 using namespace std;

class A{
    public:
    static int x;
    void incrementx(){
        x++;
    }
};
int A::x;
 int main(){
   A a;
   a.x = 5;
   a.incrementx();
   cout<<a.x<<endl;
   A b;
   b.incrementx();
   cout<<b.x<<endl;
    return 0;
 }
