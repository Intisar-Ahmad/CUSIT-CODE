#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    int n = 10;   // initial size (10 elements will be input)
    int choice, pos, num;

    // Step 1 & 2: Input 10 numbers
    cout << "Enter 10 numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {
        cout << "\n=== Menu ===\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Update\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // Insert
            if (n == SIZE) {
                cout << "Array Overflow! Cannot insert more elements.\n";
                break;
            }
            cout << "Enter position (0-" << n << "): ";
            cin >> pos;
            if (pos < 0 || pos > n) {
                cout << "Invalid position!\n";
                break;
            }
            cout << "Enter number to insert: ";
            cin >> num;
            for (int i = n; i > pos; i--) {
                arr[i] = arr[i - 1];  // Shift right
            }
            arr[pos] = num;
            n++;
            cout << "Inserted successfully!\n";
            break;

        case 2: // Delete
            if (n == 0) {
                cout << "Array Underflow! No elements to delete.\n";
                break;
            }
            cout << "Enter position (0-" << n - 1 << "): ";
            cin >> pos;
            if (pos < 0 || pos >= n) {
                cout << "Invalid position!\n";
                break;
            }
            for (int i = pos; i < n - 1; i++) {
                arr[i] = arr[i + 1];  // Shift left
            }
            n--;
            cout << "Deleted successfully!\n";
            break;

        case 3: // Search
            cout << "Enter number to search: ";
            cin >> num;
            {
                bool found = false;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == num) {
                        cout << "Number found at index " << i << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Number not found.\n";
            }
            break;

        case 4: // Update
            cout << "Enter index (0-" << n - 1 << "): ";
            cin >> pos;
            if (pos < 0 || pos >= n) {
                cout << "Invalid index!\n";
                break;
            }
            cout << "Enter new value: ";
            cin >> num;
            arr[pos] = num;
            cout << "Updated successfully!\n";
            break;

        case 5: // Display
            if (n == 0) cout << "Array is empty.\n";
            else {
                cout << "Array elements: ";
                for (int i = 0; i < n; i++) cout << arr[i] << " ";
                cout << endl;
            }
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

        // Show array state after each valid operation
        if (choice >= 1 && choice <= 5 && n > 0) {
            cout << "Current array: ";
            for (int i = 0; i < n; i++) cout << arr[i] << " ";
            cout << endl;
        }

    } while (choice != 6);

    return 0;
}
