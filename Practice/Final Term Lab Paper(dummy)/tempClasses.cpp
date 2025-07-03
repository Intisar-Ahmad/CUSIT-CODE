#include <iostream>

using namespace std;

template <typename type>
class myClass{
    public:
    type data;

    static int value;

    myClass(type d):data(d){
        cout << data << endl;
    }
};
template <typename type>
int myClass<type>::value = 0;



int main() {
 myClass<int> obj(97);
    myClass<int> obj2(100);
    myClass<int> obj3(10);

    cout << obj.value<<endl;
    cout << obj2.value<<endl;
    
    obj.value = 6;
    
    cout << obj.value<<endl;
    cout << obj2.value<<endl;
    cout << obj3.value<<endl;



    myClass<float> objf(97.98230); 

   cout << objf.value << endl;
    // myClass<string> obj3("bhino");
    return 0;
}