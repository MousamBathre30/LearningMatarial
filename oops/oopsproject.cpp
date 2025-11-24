#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm> // For std::remove_if
using namespace std;

// Abstract class for Library
class Library {
public:
    virtual void addBook() = 0;
    virtual void removeBook() = 0;
    virtual void viewBooks() const = 0;
};

// Book class
class Book {
private:
    string title, author;
    int id;
    bool isAvailable;

public:
    Book(int id, string title, string author) : id(id), title(title), author(author), isAvailable(true) {}
    
    void display() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author
             << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }

    // Getters and setters
    int getId() const { return id; } // Add this function to access the book ID
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool checkAvailability() const { return isAvailable; }
    void borrowBook() { isAvailable = false; }
    void returnBook() { isAvailable = true; }
};

// User class
class User {
protected:
    string name;
    int userID;

public:
    User(string name, int userID) : name(name), userID(userID) {}
    virtual void displayDetails() const {
        cout << "User ID: " << userID << ", Name: " << name << endl;
    }
};

// Member class
class Member : public User {
private:
    vector<int> borrowedBooks;

public:
    Member(string name, int userID) : User(name, userID) {}

    void borrowBook(int bookID) {
        borrowedBooks.push_back(bookID);
        cout << "Book borrowed successfully!\n";
    }

    void returnBook(int bookID) {
        borrowedBooks.erase(remove(borrowedBooks.begin(), borrowedBooks.end(), bookID), borrowedBooks.end());
        cout << "Book returned successfully!\n";
    }

    void displayDetails() const override {
        User::displayDetails();
        cout << "Borrowed Books: ";
        for (int id : borrowedBooks)
            cout << id << " ";
        cout << endl;
    }
};

// Admin class
class Admin : public User, public Library {
private:
    vector<Book> books;

public:
    Admin(string name, int userID) : User(name, userID) {}

    void addBook() override {
        int id;
        string title, author;
        cout << "Enter Book ID, Title, and Author: ";
        cin >> id;
        cin.ignore();
        getline(cin, title);
        getline(cin, author);
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void removeBook() override {
        int id;
        cout << "Enter Book ID to remove: ";
        cin >> id;
        auto it = remove_if(books.begin(), books.end(), [id](Book &b) { return b.getId() == id; });
        if (it != books.end()) {
            books.erase(it, books.end());
            cout << "Book removed successfully!\n";
        } else {
            cout << "Book with ID " << id << " not found.\n";
        }
    }

    void viewBooks() const override {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }
        for (const Book &book : books)
            book.display();
    }
};

// Main Function
int main() {
    Admin admin("Admin", 1);
    Member member("John Doe", 101);

    // Sample operations
    admin.addBook();
    admin.viewBooks();
    member.borrowBook(1);
    member.displayDetails();
    admin.viewBooks();

    return 0;
}
