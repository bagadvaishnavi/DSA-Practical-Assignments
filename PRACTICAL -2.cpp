#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
    int table[SIZE];

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1;
    }

    void insert(int patientID) {
        int index = patientID % SIZE;

        while (table[index] != -1) {
            index = (index + 1) % SIZE;
        }

        table[index] = patientID;
        cout << "Patient ID inserted at index " << index << endl;
    }

    void search(int patientID) {
        int index = patientID % SIZE;
        int start = index;

        while (table[index] != -1) {
            if (table[index] == patientID) {
                cout << "Patient ID found at index " << index << endl;
                return;
            }

            index = (index + 1) % SIZE;

            if (index == start)
                break;
        }

        cout << "Patient ID not found." << endl;
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < SIZE; i++)
            cout << i << " : " << table[i] << endl;
    }
};

int main() {
    HashTable h;

    h.insert(101);
    h.insert(111);
    h.insert(121);
    h.insert(105);

    h.display();

    h.search(111);
    h.search(200);

    return 0;
}