
'''include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    cout << x << " inserted into queue.\n";
}

void dequeue() {
    if (front == NULL) {
        cout << "Queue Underflow! Queue is empty.\n";
        return;
    }

    Node* temp = front;
    cout << "Deleted element: " << front->data << endl;

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
}

void display() {
    if (front == NULL) {
        cout << "Queue is empty.\n";
        return;
    }

    Node* temp = front;

    cout << "Queue elements: ";
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, x;

    do {
        cout << "\n--- Queue Using Linked List ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                enqueue(x);
                break;

            case 2:
                dequeue();
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
}'''


#include <iostream>
#include <stack>
using namespace std;

stack<int> s1, s2;

void enqueue(int x) {
    s1.push(x);
    cout << x << " inserted into queue.\n";
}

void transfer() {
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
}

void dequeue() {
    if (s2.empty()) {
        transfer();
    }

    if (s2.empty()) {
        cout << "Queue Underflow! Queue is empty.\n";
        return;
    }

    cout << "Deleted element: " << s2.top() << endl;
    s2.pop();
}

void display() {
    if (s1.empty() && s2.empty()) {
        cout << "Queue is empty.\n";
        return;
    }

    stack<int> temp1 = s1;
    stack<int> temp2 = s2;

    cout << "Queue elements: ";

    while (!temp2.empty()) {
        cout << temp2.top() << " ";
        temp2.pop();
    }

    stack<int> temp3;

    while (!temp1.empty()) {
        temp3.push(temp1.top());
        temp1.pop();
    }

    while (!temp3.empty()) {
        cout << temp3.top() << " ";
        temp3.pop();
    }

    cout << endl;
}

int main() {
    int choice, x;

    do {
        cout << "\n--- Queue Using Two Stacks ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element: ";
                cin >> x;
                enqueue(x);
                break;

            case 2:
                dequeue();
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

