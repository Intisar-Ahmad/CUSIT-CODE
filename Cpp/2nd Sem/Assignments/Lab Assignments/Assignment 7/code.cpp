#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line = "Bhino is a very good and nice boy. Bhino likes coding and enjoys learning new things.";

    // Write to file
    ofstream outFile("example.txt");
    if (outFile.is_open()) {
        outFile << line;
        outFile.close();
    } else {
        cout << "Unable to open file for writing.\n";
    }

    // Read from file
    ifstream inFile("example.txt");
    if (inFile.is_open()) {
        string readLine;
        getline(inFile, readLine);
        cout << "Read from file: " << readLine << endl;
        inFile.close();
    } else {
        cout << "Unable to open file for reading.\n";
    }

    return 0;
}
