#include <iostream>
#include <string>
using namespace std;

struct Friend {
    string name;
    string mobile;
};

void display(Friend phoneBook[], int n) {
    cout << "\n--- Phone Book ---\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << phoneBook[i].name
             << " - " << phoneBook[i].mobile << endl;
    }
}

// Sentinel Search
int sentinelSearch(Friend phoneBook[], int n, string key) {
    if (n == 0)
        return -1;

    // Store last element temporarily
    Friend last = phoneBook[n - 1];
    phoneBook[n - 1].name = key;

    int i = 0;

    while (phoneBook[i].name != key)
        i++;

    // Restore last element
    phoneBook[n - 1] = last;

    if (i < n - 1 || phoneBook[n - 1].name == key)
        return i;

    return -1;
}

// Insert friend in sorted order
void insertFriend(Friend phoneBook[], int &n, string name, string mobile) {
    int pos = 0;

    while (pos < n && phoneBook[pos].name < name)
        pos++;

    // Shift elements to the right
    for (int i = n; i > pos; i--)
        phoneBook[i] = phoneBook[i - 1];

    phoneBook[pos].name = name;
    phoneBook[pos].mobile = mobile;
    n++;

    cout << "\nFriend inserted successfully!\n";
}

int main() {
    Friend phoneBook[100];
    int n;

    cout << "Enter number of friends: ";
    cin >> n;

    cout << "Enter names and mobile numbers:\n";

    for (int i = 0; i < n; i++) {
        cout << "\nFriend " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> phoneBook[i].name;
        cout << "Mobile: ";
        cin >> phoneBook[i].mobile;
    }

    // Sort phone book by name
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (phoneBook[j].name > phoneBook[j + 1].name) {
                swap(phoneBook[j], phoneBook[j + 1]);
            }
        }
    }

    display(phoneBook, n);

    string searchName;
    cout << "\nEnter friend's name to search: ";
    cin >> searchName;

    int index = sentinelSearch(phoneBook, n, searchName);

    if (index != -1) {
        cout << "\nFriend found!\n";
        cout << "Name: " << phoneBook[index].name << endl;
        cout << "Mobile: " << phoneBook[index].mobile << endl;
    } else {
        cout << "\nFriend not found in phone book.\n";

        string mobile;
        cout << "Enter mobile number to insert: ";
        cin >> mobile;

        insertFriend(phoneBook, n, searchName, mobile);
    }

    display(phoneBook, n);

    return 0;
}