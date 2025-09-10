#include <iostream>
#include<vector>
using namespace std;

class Street {
public:
    string name;
};
class City {// city have streets
    public:
    string name;
    vector<Street> streets;
};

class Province {//provinces  have cities
    public:
    string name;
    vector<City> cities;
};

class Country {//country has provinces
public:
    string name;
    vector<Province> provinces;
};




int main() {
    
    return 0;
}