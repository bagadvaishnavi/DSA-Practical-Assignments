#include <iostream>
using namespace std;

int main() {
    int marks[100] = {78, 85, 62, 91, 73};
    int n = 5;
    int choice, pos, value, search;
    
    do {
        cout << "\n--- STUDENT MARK ANALYSIS SYSTEM ---\n";
        cout << "1. Display Marks\n";
        cout << "2. Insert Mark\n";
        cout << "3. Delete Mark\n";
        cout << "4. Search Mark\n";
        cout << "5. Find Highest Mark\n";
        cout << "6. Find Lowest Mark\n";
        cout << "7. Calculate Average\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Student Marks: ";
            for (int i = 0; i < n; i++) {
                cout << marks[i] << " ";
            }
            cout << endl;
            break;

        case 2:
            cout << "Enter position (0 to " << n << "): ";
            cin >> pos;
            cout << "Enter mark: ";
            cin >> value;

            if (pos >= 0 && pos <= n) {
                for (int i = n; i > pos; i--) {
                    marks[i] = marks[i - 1];
                }
                marks[pos] = value;
                n++;

                cout << "Mark inserted successfully.\n";
            } else {
                cout << "Invalid position!\n";
            }
            break;

        case 3:
            cout << "Enter position to delete (0 to " << n - 1 << "): ";
            cin >> pos;

            if (pos >= 0 && pos < n) {
                for (int i = pos; i < n - 1; i++) {
                    marks[i] = marks[i + 1];
                }
                n--;

                cout << "Mark deleted successfully.\n";
            } else {
                cout << "Invalid position!\n";
            }
            break;

        case 4:
            cout << "Enter mark to search: ";
            cin >> search;

            bool found;
            found = false;

            for (int i = 0; i < n; i++) {
                if (marks[i] == search) {
                    cout << "Mark found at position " << i << endl;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Mark not found.\n";
            }
            break;

        case 5: {
            int highest = marks[0];

            for (int i = 1; i < n; i++) {
                if (marks[i] > highest) {
                    highest = marks[i];
                }
            }

            cout << "Highest Mark = " << highest << endl;
            break;
        }

        case 6: {
            int lowest = marks[0];

            for (int i = 1; i < n; i++) {
                if (marks[i] < lowest) {
                    lowest = marks[i];
                }
            }

            cout << "Lowest Mark = " << lowest << endl;
            break;
        }

        case 7: {
            int sum = 0;

            for (int i = 0; i < n; i++) {
                sum += marks[i];
            }

            float average = (float)sum / n;

            cout << "Average Marks = " << average << endl;
            break;
        }

        case 8:
            cout << "Program ended.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 8);

    return 0;
}