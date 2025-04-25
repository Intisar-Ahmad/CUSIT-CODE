#include<iostream>

using namespace std;

class Booking{

private:
    int BookingId;
    string riderName;
    string rideType;
    float distanceTraveled;

    public:
    Booking():BookingId{16880},riderName{"Intisar Ahmad"},rideType{"Standard"},distanceTraveled{0}{}

    void setRiderName(string name){
        riderName = name;
    }

    void setRideType(string rideType){
        if(rideType == "Standard" || rideType == "Business" || rideType == "Premium" || rideType == "standard" || rideType == "business" || rideType == "premium"){
            this->rideType = rideType;
        }
        else{
            cout<<"Couldn't set ride type please choose between Standard , Premium or Business"<<endl;
        }
    }

    void setDistanceTraveled(float distance){
        if(distance < 0){
            cout<<"Invalid Input"<<endl;
        }
        else{
            distanceTraveled = distance;
        }
    }


    string getRiderName(){
        return riderName;
    }
    string getRideType(){
        return rideType;
    }
    float getDistanceTraveled(){
        return distanceTraveled;
    }


    void displayRideInfo(){
        cout<<"ID:"<<BookingId<<endl;
        cout<<"Rider Name:"<<riderName<<endl;
        cout<<"Ride Type:"<<rideType<<endl;
        cout<<"Distance Covered:"<<distanceTraveled<<endl;
    }

};

int main(){
    Booking b1;

    b1.setRiderName("Intisar Ahmad");
    b1.setRideType("Standard");
    b1.setRideType("something else");//this is wrong
    b1.setDistanceTraveled(100.0);
    b1.displayRideInfo();
    return 0;
}