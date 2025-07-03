#include <iostream>

using namespace std;

int main() {

    try
    {


        throw runtime_error("password is invalid");
      
    }
    catch(const std::exception& e)
    {
      cout << "Caught std::exception: " << e.what() << endl;
    }
    catch(...){
        cout << "unexpected error happened" << endl;
    }
    
// programs continue









    try {
        int option;
        cout << "Enter 1 to throw int, 2 for string, 3 for std::exception: ";
        cin >> option;

        if (option == 1)
            throw 42;
        else if (option == 2)
            throw string("String exception!");
        else if (option == 3)
            throw runtime_error("Standard runtime error!");
        else
            throw 'X';  // unknown type
    }
    catch (int e) {
        cout << "Caught int: " << e << endl;
    }
    catch (string& s) {
        cout << "Caught string: " << s << endl;
    }
    catch (exception& e) {
        cout << "Caught std::exception: " << e.what() << endl;
    }
    catch (...) {
        cout << "Caught unknown exception!" << endl;
    }

    return 0;
}
