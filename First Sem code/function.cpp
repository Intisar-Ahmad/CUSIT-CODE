#include<iostream>

using namespace std;
void add(int *a){
    (*a)+=(*a);
}

void dgo(char &a){
    a = 'k';
}
int main(){
   char a = 'a';
   //dgo(a);
   cout<<a<<endl;
   char *ptr = &a;
   cout<<(int)ptr<<endl;
   cout<<ptr;
    return 0;
}