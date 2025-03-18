#include <iostream>

using namespace std;

/*
Task 7: Create a class Robot with the following attributes:
Note: Set your student ID and name in robotName and id variables.
• robotName
• id
• color
• material
• price
Requirements:
• Material must be either "plastic" or "metal". If an invalid value is provided, display:
  "Invalid Input! Material must be either plastic or metal."
• Price must be greater than 0. If an invalid value is provided, display:
  "Invalid Input! Price must be greater than 0."
• Methods: walk(), jump(), speak()
*/

class Robot {
private:
    string robotName; 
    int id;               
    string color;
    string material;
    float price;

public:
    void setColor(string c) { color = c; }
    void setRobotName(string r) { robotName = r; }
    void setId(int i) { id = i; }

    void setMaterial(string m) {
        if (m == "plastic" || m == "metal") {
            material = m;
        } else {
            cout << "Invalid Input! Material must be either plastic or metal." << endl;
        }
    }

    void setPrice(float p) {
        if (p > 0) {
            price = p;
        } else {
            cout << "Invalid Input! Price must be greater than 0." << endl;
        }
    }

    void walk() { cout << robotName << " is walking..." << endl; }
    void jump() { cout << robotName << " is jumping..." << endl; }
    void speak() { cout << robotName << " is speaking and says: Intisar is great" << endl; }

    void displayRobotInfo() {
        cout << "Robot " << robotName << " color is " << color  << endl;
        cout << "Robot " << robotName << " id is " << id  << endl;
        cout << "Robot " << robotName << " material is " << material  << endl;
        cout << "Robot " << robotName << " price is " << price  << endl;
    }
};

int main() {
    Robot myRobot;
    myRobot.setRobotName("Intisar");
    myRobot.setId(16880);
    myRobot.setColor("Red");
    // myRobot.setMaterial("wood"); //Invalid Input
    // myRobot.setPrice(-50);      //Invalid Input!  
    myRobot.setMaterial("metal"); 
    myRobot.setPrice(1500);       

    myRobot.displayRobotInfo();

    myRobot.walk();
    myRobot.jump();
    myRobot.speak();

    return 0;
}
