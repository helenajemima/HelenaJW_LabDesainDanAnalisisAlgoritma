#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;

public:
    void setTitle(string Title) {
        title = Title;
    }

    string getTitle() {
        return title;
    }

    void setAuthor(string Author) {
        author = Author;
    }

    string getAuthor() {
        return author;
    }
};

class Library {
private:
    string name;
    int npm;
    Book borrow[10];

public:
    void setName(string Name) {
        name = Name;
    }

    string getName() {
        return name;
    }

    void setNPM(int NPM) {
        npm = NPM;
    }

    int getNPM() {
        return npm;
    }

    void brwbook(string title, string author) {
        for (int i = 0; i < 10; ++i) {
            if (borrow[i].getTitle().empty()) {
                borrow[i].setTitle(title);
                borrow[i].setAuthor(author);
                break;
            }
        }
    }

    void returnbook(string title) {
        for (int i = 0; i < 10; ++i) {
            if (borrow[i].getTitle() == title) {
                borrow[i].setTitle("");
                borrow[i].setAuthor("");
                break;
            }
        }
    }

    void display() {
        cout << "Books borrowed:\n";
        for (int i = 0; i < 10; ++i) {
            if (!borrow[i].getTitle().empty()) {
                cout << "- " << borrow[i].getTitle() << " by " << borrow[i].getAuthor() << endl;
            }
        }
    }
};

int main() {
    Library user;
    string name, title, author;
    int npm;
    char choice;
    int numbook;

    cout << "Enter your name: ";
    getline(cin, name);
    user.setName(name);

    cout << "Enter your NPM: ";
    cin >> npm;
    user.setNPM(npm);

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Borrow a book\n";
        cout << "2. Return a book\n";
        cout << "Enter your choice (1/2): ";
        cin >> choice;
        cin.ignore(); 

        if (choice == '1') {
            cout << "\nEnter the number of books you want to borrow: ";
            cin >> numbook;
            cin.ignore(); 

            cout << "\nSelect the book/s you want to borrow:\n";
            for (int i = 0; i < numbook; ++i) {
                cout << "Enter book " << i + 1 << " title: ";
                getline(cin, title);
                cout << "Enter book " << i + 1 << " author: ";
                getline(cin, author);
                user.brwbook(title, author);
            }

            cout << "\nName: " << user.getName() << endl;
            cout << "NPM: " << user.getNPM() << endl;
            user.display();
            cout << "Please return the book/s after 1 month\n";
        } else if (choice == '2') {
            cout << "\nEnter the book title you want to return:\n";
            getline(cin, title);
            user.returnbook(title);
            cout << "Book returned successfully.\n";
            cout << "\nThank you for returning. See you next time!\n";            

            cout << "\nDo you want to borrow other books? (y/n): ";
            cin >> choice;
            cin.ignore(); 
        }
    } while (toupper(choice) == 'Y');

    return 0;
}

