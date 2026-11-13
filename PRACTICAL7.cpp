
#include <iostream>
#include <deque>
#include <string>
using namespace std;

struct Task {
    string name;
    int priority;
};

int main() {
    deque<Task> dq;
    int choice;

    do {
        cout << "\n--- TASK SCHEDULER ---\n";
        cout << "1. Add Task at Front\n";
        cout << "2. Add Task at Rear\n";
        cout << "3. Process Highest Priority Task\n";
        cout << "4. Display Tasks\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
            case 2: {
                Task t;

                cout << "Enter task name (no spaces): ";
                cin >> t.name;

                cout << "Enter task priority: ";
                cin >> t.priority;

                if (choice == 1)
                    dq.push_front(t);
                else
                    dq.push_back(t);

                cout << "Task added successfully!\n";
                break;
            }

            case 3: {
                if (dq.empty()) {
                    cout << "No tasks available!\n";
                } else {
                    int maxIndex = 0;

                    for (int i = 1; i < (int)dq.size(); i++) {
                        if (dq[i].priority > dq[maxIndex].priority)
                            maxIndex = i;
                    }

                    cout << "Processing Task: "
                         << dq[maxIndex].name << endl;
                    cout << "Priority: "
                         << dq[maxIndex].priority << endl;

                    dq.erase(dq.begin() + maxIndex);
                }
                break;
            }

            case 4: {
                if (dq.empty()) {
                    cout << "No tasks available!\n";
                } else {
                    cout << "\nTasks in Scheduler:\n";

                    for (int i = 0; i < (int)dq.size(); i++) {
                        cout << "Task: " << dq[i].name
                             << " | Priority: "
                             << dq[i].priority << endl;
                    }
                }
                break;
            }

            case 5:
                cout << "Exiting Task Scheduler.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
