#include <iostream>

using namespace std;

// Q#4: Our city university is conducting an exam in auditorium which has
// 5 rows with 6 seats in each row. The attendance status of the students
// is stored in a 2D array as a grid where true means the student is sitting
// in the seat and is present, while false means the student is absent


// Display the attendance seats status where students are present
// (true) as Present and the seats where students are absent (false)
// as Absent.
// • Also count and show the no of absent (false) seats as well.

int main() {
    bool arr [5][6] = {
 {true, false, true, false, false, true},
 {false, true, true, true, false, false},
 {true, true, false, false, true, true},
 {false, false, true, true, false, false},
  {true, true, false, true, true, false}
 };

    int absentCount = 0;

 for (int i = 0; i < 5; i++)
 {

    for (int j = 0; j < 6; j++)
    {
        if(arr[i][j]){
            cout << "Present";
        }
        else{
            cout << "Absent";
            absentCount++;
        }
        cout << " ";
    }
    cout << endl;
 }
 
 cout << "The total number of students absent are:" << absentCount << endl;

    return 0;
}