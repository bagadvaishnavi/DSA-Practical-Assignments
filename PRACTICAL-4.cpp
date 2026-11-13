
#include <iostream>
#include <string>
using namespace std;

struct Song {
    string name;
    Song* next;
};

Song* head = NULL;

void addSong(string name) {
    Song* newSong = new Song;
    newSong->name = name;

    if (head == NULL) {
        head = newSong;
        newSong->next = head;
    } else {
        Song* temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newSong;
        newSong->next = head;
    }

    cout << "Song added successfully!\n";
}

void displayPlaylist() {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }

    Song* temp = head;

    cout << "\nMusic Playlist:\n";
    do {
        cout << temp->name << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "(Back to first song)\n";
}

void playNext() {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }

    static Song* current = NULL;

    if (current == NULL) {
        current = head;
    } else {
        current = current->next;
    }

    cout << "Now Playing: " << current->name << endl;
}

void deleteSong(string name) {
    if (head == NULL) {
        cout << "Playlist is empty!\n";
        return;
    }

    Song* current = head;
    Song* previous = NULL;

    do {
        if (current->name == name) {
            if (current->next == current) {
                head = NULL;
            } else {
                if (previous == NULL) {
                    Song* last = head;

                    while (last->next != head) {
                        last = last->next;
                    }

                    head = head->next;
                    last->next = head;
                } else {
                    previous->next = current->next;
                }
            }

            delete current;
            cout << "Song deleted successfully!\n";
            return;
        }

        previous = current;
        current = current->next;

    } while (current != head);

    cout << "Song not found!\n";
}

int main() {
    int choice;
    string name;

    do {
        cout << "\n--- Music Playlist Management ---\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Play Next Song\n";
        cout << "4. Delete Song\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter song name: ";
                getline(cin >> ws, name);
                addSong(name);
                break;

            case 2:
                displayPlaylist();
                break;

            case 3:
                playNext();
                break;

            case 4:
                cout << "Enter song name to delete: ";
                getline(cin >> ws, name);
                deleteSong(name);
                break;

            case 5:
                cout << "Exiting playlist...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
