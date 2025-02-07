#include <iostream>

using namespace std;

int main()
{
    long double num1, num2;//Taking two long doubles for bigger and more complex inputs 
    int continuation = 1;//Taking a variable to determine continuation
    while (continuation != 0 )//While loop to keep program running
    {
        cout << "Please Enter:\n0 if you want to exit\n1 if you want to continue:";//Asking user weather they want to continue or quit
        cin >> continuation;//Taking their input

        if (cin.fail())//Handling error(In case user enters some random character or any other reason the input fails)
        //cin.fail() checks if cin failed and marks it as failed
        {
            cin.clear();//this clears the failed status from the cin
            cin.ignore(1000, '\n');//This deletes upto a thousand characters from the input buffer
            cout << "Invalid Input\nProgram Terminated" << endl;
            break;//BReaks through the loop and terminates the program
        }
        else if (continuation == 0)//checks if user input 0 and then terminates the program
        {
            cout << "Program Terminated" << endl;
            break;
        }
        else if(continuation!=1){//Checks if user input anything number other than 1 because the cin.fail wont detect false numbers
            cout<<"Invalid Input"<<endl;//This also implicitly makes 1 the number to continue
            continue;
        }
        cout << "Please enter two numbers : ";
        cin >> num1 >> num2;//Taking num1 and num2 as input
        if (cin.fail())//Checking their validity
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input." << endl;
            continue;
        }
        char op;
        cout << "Please choose:\n'+' for addition \n'-' for subtraction \n'*' for multiplication\n'/' for division \n'm' to find the maximum of these two numbers\n'0' to find the minimum:";
        cin >> op;
        switch (op)//Taking the operation to be performed as input
        //% can't be taken here as it doesn't work on float or doubles
        {
            int sequence;// This is important for subtract and divide
        case '+':
            cout << "Addition : " << num1 + num2 << endl;//Adds the numbers
            break;
        case '-':

            cout << "Please Enter which number you want to subtract from i.e (number you choose - number you didn't choose)\n1 or 2: ";
            cin >> sequence;//here the sequence is important because the answer may change 
            switch (sequence)//Switch for checking sequence
            {
            case 1:
                cout << "Subtraction : " << num1 - num2 << endl;
                break;
            case 2:
                cout << "Subtraction : " << num2 - num1 << endl;
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
            }
            break;
        case '*':
            cout << "Multiplication : " << num1 * num2 << endl;//multiplication
            break;
        case '/':

            cout << "Please Enter which number you want to divide with i.e (number you didn't choose/number you choose)\n1 or 2:";
            cin >> sequence;
            switch (sequence)//Same here the answer may change on sequence
            {
            case 1:
                if (num1 != 0)//Checking if the Dividend is zero
                {
                    cout << "Division : " << num2 / num1 << endl;
                }
                else
                {
                    cout << "Division not possible" << endl;
                }
                break;
            case 2:
                if (num2 != 0)
                {
                    cout << "Division : " << num1 / num2 << endl;
                }
                else
                {
                    cout << "Division not possible" << endl;
                }
                break;
            default:
                cout << "Invalid Input" << endl;
                break;
            }
            break;
        case 'm':
            if (num1 > num2)//Checking for max
            {
                cout << num1 << " is the max" << endl;
            }
            else if (num2 > num1)
            {
                cout << num2 << " is the max" << endl;
            }
            else//In case both are equal
            {
                cout << "Both numbers are equal" << endl;
            }
            break;
        case '0':
            if (num1 < num2)//Checking for minimum
            {
                cout << num1 << " is the min" << endl;
            }
            else if (num2 < num1)
            {
                cout << num2 << " is the min" << endl;
            }
            else
            {
                cout << "Both numbers are equal" << endl;
            }
            break;
        default://If user inputs an invalid operation
            cout << "Invalid Input" << endl;
            break;
        }
        cin.ignore(1000,'\n');//clears the buffer just in case
    }

    return 0;
}