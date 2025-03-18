#include<iostream>
#include<vector>
#include<climits>

using namespace std;

class Box{
    private:
    float length,width,height;

    public:
    float getVolume();
    
    void setLength( float len );
      void setWidth( float wid );
      void setHeight( float hei );
};

//scope resolution operator

float Box :: getVolume(){
    return length*height*width;
}

void Box :: setLength(float len ){
    length = len;
}

int main(){
    Box box1;
    return 0;
}