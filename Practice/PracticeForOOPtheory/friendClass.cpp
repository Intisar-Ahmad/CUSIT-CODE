#include <iostream>

using namespace std;

class A{
 private:
 int x = 10,y = 10;

 friend class B;
};


class B{
  public:

  void show(A obj){
    cout << obj.x << endl;
  }

  friend class A;
};

// class C:public B{
//    public:
//    void display(A obj){
//     cout << obj.x << endl;
//    }
// };

int main() {
    A obj;
    B obj1;

    obj1.show(obj);
    return 0;
}