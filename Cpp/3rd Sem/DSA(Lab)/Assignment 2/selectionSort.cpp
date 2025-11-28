#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int> &array)
{
    int size = array.size();
    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < size; i++)
    {
        min = INT_MAX;
        for (int j = i; j < size; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                minIndex = j;
            }
        }
        array[minIndex] = array[i];
        array[i] = min;
    }
}

void displayArr(const vector<int> &array ){
    for (auto &&i : array)
    {
        cout << i << " ";
    }
    cout << endl;   
}


int main()
{
    vector<int> arr = {3, 1, 6, -4, 3, 10};

    selectionSort(arr);
    displayArr(arr);
    return 0;
}