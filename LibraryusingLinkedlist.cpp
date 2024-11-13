
#include <iostream>
#include <string>
using namespace std;

struct Book {
    int id;
    string title;
    string author;
    Book* next;
};

class Library {
private:
    Book* head;

public:
    Library() : head(nullptr) {}

    // Add a new book to the library
    void addBook(int id, const string& title, const string& author) {
        Book* newBook = new Book{id, title, author, nullptr};
        if (!head) {
            head = newBook;
        } else {
            Book* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
        cout << "✅ Book added successfully: " << title << "\n";
    }

    // Delete a book by ID
    void deleteBook(int id) {
        if (!head) {
            cout << "⚠️ Library is empty. No book to delete.\n";
            return;
        }
        if (head->id == id) {
            Book* temp = head;
            head = head->next;
            delete temp;
            cout << "✅ Book deleted successfully.\n";
            return;
        }
        Book* current = head;
        Book* previous = nullptr;
        while (current && current->id != id) {
            previous = current;
            current = current->next;
        }
        if (current) {
            previous->next = current->next;
            delete current;
            cout << "✅ Book deleted successfully.\n";
        } else {
            cout << "⚠️ Book with ID " << id << " not found.\n";
        }
    }

    // Display all books in the library
    void showBooks() {
        if (!head) {
            cout << "⚠️ No books in the library.\n";
            return;
        }
        Book* temp = head;
        cout << "\n📚 Library Books:\n";
        while (temp) {
            cout << "ID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author << "\n";
            temp = temp->next;
        }
    }

    // Search for a book by ID
    void findBook(int id) {
        Book* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "✅ Book found: ID: " << temp->id << ", Title: " << temp->title << ", Author: " << temp->author << "\n";
                return;
            }
            temp = temp->next;
        }
        cout << "⚠️ Book with ID " << id << " not found.\n";
    }

    // Destructor to clear all dynamically allocated memory
    ~Library() {
        while (head) {
            Book* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Library library;
    int choice, id;
    string title, author;

    do {
        cout << "\n------ Library Management System ------\n";
        cout << "1. Add Book\n2. Delete Book\n3. Show Books\n4. Find Book\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore(); // ignore newline character from previous input
                cout << "Enter Book Title: ";
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                library.addBook(id, title, author);
                break;

            case 2:
                cout << "Enter Book ID to delete: ";
                cin >> id;
                library.deleteBook(id);
                break;

            case 3:
                library.showBooks();
                break;

            case 4:
                cout << "Enter Book ID to search: ";
                cin >> id;
                library.findBook(id);
                break;

            case 5:
                cout << "👋 Exiting the system. Thank you!\n";
                break;

            default:
                cout << "❌ Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
