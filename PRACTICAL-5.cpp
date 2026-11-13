
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> q1, q2;

void push(int x) {
    q2.push(x);

    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }

    swap(q1, q2);

    cout << x << " pushed into stack.\n";
}

void pop() {
    if (q1.empty()) {
        cout << "Stack Underflow! Stack is empty.\n";
        return;
    }

    cout << "Popped element: " << q1.front() << endl;
    q1.pop();
}

void display() {
    if (q1.empty()) {
        cout << "Stack is empty.\n";
        return;
    }

    queue<int> temp = q1;

    cout << "Stack elements (top to bottom): ";

    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }

    cout << endl;
}

int main() {
    int choice, x;

    do {
        cout << "\n--- Stack Using Two Queues ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                push(x);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
