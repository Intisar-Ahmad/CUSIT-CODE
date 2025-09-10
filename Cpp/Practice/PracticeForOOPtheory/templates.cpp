#include <iostream>

// create a class Pair<T1,T2> 


using namespace std;


template<typename T1,typename T2>
class Pair{
    public:
    T1 x;
    T2 y;

    Pair(T1 x,T2 y):x(x),y(y){}

    // Pair operator+(Pair &b){
    //     return new Pair(this->x)
    // }

    void display(){
        cout << x << " " << y << endl;
    }
};


template<typename T>
void sumthisbitchup(T arr[],int size){
    T sum = T();
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    cout<< sum << endl;
}




int main() {
    // Pair p(9,8);
    // Pair p2("bhino",4.5f);
    // Pair p3(9,'a');


    // p.display(); 
    // p2.display(); 
    // p3.display(); 

    int arr[] = {1,2,3,4,5};
    string arr3[] = {"1","2","3","4","5"};

    sumthisbitchup(arr,5);
    sumthisbitchup(arr3,5);

    return 0;
}