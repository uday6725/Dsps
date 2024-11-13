#include <iostream>
#include <string>
using namespace std;

// Define the structure to store song data
struct Song {
    int songID;
    string title;
    string artist;
    double duration;
    Song* next;
};

// Music Library System class
class MusicLibrary {
private:
    Song* head;

public:
    MusicLibrary() : head(nullptr) {}

    // Add a song to the library
    void addSong(int id, const string& songTitle, const string& songArtist, double songDuration) {
        Song* newSong = new Song{id, songTitle, songArtist, songDuration, nullptr};
        
        // Add to the end of the list
        if (!head) {
            head = newSong;
        } else {
            Song* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newSong;
        }
        cout << "Song added: " << songTitle << " by " << songArtist << "\n";
    }

    // Remove a song by song ID
    void removeSong(int songID) {
        if (!head) {
            cout << " No songs available.\n";
            return;
        }

        // If the song to be removed is the first song (head)
        if (head->songID == songID) {
            Song* temp = head;
            head = head->next;
            delete temp;
            cout << " Song removed successfully.\n";
            return;
        }

        // Traverse the list to find the song
        Song* current = head;
        Song* previous = nullptr;
        while (current && current->songID != songID) {
            previous = current;
            current = current->next;
        }

        if (current) {
            previous->next = current->next;
            delete current;
            cout << " Song removed successfully.\n";
        } else {
            cout << " Song with ID " << songID << " not found.\n";
        }
    }

    // Display all songs in the library
    void showSongs() {
        if (!head) {
            cout << " No songs in the library.\n";
            return;
        }

        Song* temp = head;
        cout << "\n Songs in the Library:\n";
        while (temp) {
            cout << "ID: " << temp->songID << ", Title: " << temp->title << ", Artist: " << temp->artist << ", Duration: " << temp->duration << " mins\n";
            temp = temp->next;
        }
    }

    // Search for a song by song ID
    void findSong(int songID) {
        Song* temp = head;
        while (temp) {
            if (temp->songID == songID) {
                cout << " Song found: ID: " << temp->songID << ", Title: " << temp->title << ", Artist: " << temp->artist << ", Duration: " << temp->duration << " mins\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Song with ID " << songID << " not found.\n";
    }

    // Destructor to free memory
    ~MusicLibrary() {
        while (head) {
            Song* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Main function to interact with the system
int main() {
    MusicLibrary library;
    int choice, songID;
    string songTitle, songArtist;
    double songDuration;

    do {
        cout << "\n------ Music Library Management System ------\n";
        cout << "1. Add Song\n2. Remove Song\n3. Show Songs\n4. Find Song\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Song ID: ";
                cin >> songID;
                cin.ignore();  // To ignore the newline character
                cout << "Enter Song Title: ";
                getline(cin, songTitle);
                cout << "Enter Artist Name: ";
                getline(cin, songArtist);
                cout << "Enter Song Duration (in minutes): ";
                cin >> songDuration;
                library.addSong(songID, songTitle, songArtist, songDuration);
                break;

            case 2:
                cout << "Enter Song ID to remove: ";
                cin >> songID;
                library.removeSong(songID);
                break;

            case 3:
                library.showSongs();
                break;

            case 4:
                cout << "Enter Song ID to search: ";
                cin >> songID;
                library.findSong(songID);
                break;

            case 5:
                cout << "Exiting the system. Thank you for using the Music Library.\n";
                break;

            default:
                cout << " Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
