#include<iostream>
#include<fstream>
#include<windows.h>
using namespace std;

class Library {
    string id, name, author, searchId;
    fstream file;

public:
    void login();
    void menu();
    void addBook();
    void viewBooks();
    void searchBook();
    void updateBook();
    void deleteBook();
    void countBooks();
};

// ---------------- LOGIN ----------------
void Library::login() {
    string user, pass;

    cout << "===== LIBRARY LOGIN =====\n";
    cout << "Username: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    if(user == "admin@21" && pass == "212169") { //for library user
        cout << "\nLogin Successful!";
        Sleep(1000);
        menu();
    }
    else {
        cout << "\nInvalid Login!";
    }
}

// ---------------- MENU ----------------
void Library::menu() {
    int choice;

    while(true) {
        system("cls");
        cout << "\n===== LIBRARY MANAGEMENT =====\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Total Books\n";
        cout << "7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: updateBook(); break;
            case 5: deleteBook(); break;
            case 6: countBooks(); break;
            case 7: exit(0);
            default: cout << "Invalid Choice!";
        }

        cout << "\nPress Enter...";
        cin.get();
    }
}

// ---------------- ADD BOOK ----------------
void Library::addBook() {
    system("cls");
    cout << "Enter Book ID: ";
    getline(cin, id);
    cout << "Enter Book Name: ";
    getline(cin, name);
    cout << "Enter Author: ";
    getline(cin, author);

    file.open("Library.txt", ios::out | ios::app);
    file << id << "|" << name << "|" << author << endl;
    file.close();

    cout << "\nBook Added Successfully!";
}

// ---------------- VIEW ----------------
void Library::viewBooks() {
    system("cls");
    file.open("Library.txt", ios::in);

    if(!file) {
        cout << "No records found!";
        return;
    }

    while(getline(file, id, '|') &&
          getline(file, name, '|') &&
          getline(file, author)) {

        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAuthor: " << author;
        cout << "\n----------------------";
    }

    file.close();
}

// ---------------- SEARCH ----------------
void Library::searchBook() {
    system("cls");
    cout << "Enter Book ID: ";
    getline(cin, searchId);

    file.open("Library.txt", ios::in);
    bool found = false;

    while(getline(file, id, '|') &&
          getline(file, name, '|') &&
          getline(file, author)) {

        if(id == searchId) {
            cout << "\nBook Found!";
            cout << "\nID: " << id;
            cout << "\nName: " << name;
            cout << "\nAuthor: " << author;
            found = true;
        }
    }

    if(!found)
        cout << "\nBook Not Found!";

    file.close();
}

// ---------------- UPDATE ----------------
void Library::updateBook() {
    system("cls");
    cout << "Enter Book ID to Update: ";
    getline(cin, searchId);

    file.open("Library.txt", ios::in);
    ofstream temp("temp.txt");

    bool found = false;

    while(getline(file, id, '|') &&
          getline(file, name, '|') &&
          getline(file, author)) {

        if(id == searchId) {
            found = true;
            cout << "Enter New Name: ";
            getline(cin, name);
            cout << "Enter New Author: ";
            getline(cin, author);
        }

        temp << id << "|" << name << "|" << author << endl;
    }

    file.close();
    temp.close();

    remove("Library.txt");
    rename("temp.txt", "Library.txt");

    if(found)
        cout << "\nBook Updated!";
    else
        cout << "\nBook Not Found!";
}

// ---------------- DELETE ----------------
void Library::deleteBook() {
    system("cls");
    cout << "Enter Book ID to Delete: ";
    getline(cin, searchId);

    file.open("Library.txt", ios::in);
    ofstream temp("temp.txt");

    bool found = false;

    while(getline(file, id, '|') &&
          getline(file, name, '|') &&
          getline(file, author)) {

        if(id != searchId)
            temp << id << "|" << name << "|" << author << endl;
        else
            found = true;
    }

    file.close();
    temp.close();

    remove("Library.txt");
    rename("temp.txt", "Library.txt");

    if(found)
        cout << "\nBook Deleted!";
    else
        cout << "\nBook Not Found!";
}

// ---------------- COUNT ----------------
void Library::countBooks() {
    system("cls");
    int count = 0;

    file.open("Library.txt", ios::in);

    while(getline(file, id, '|') &&
          getline(file, name, '|') &&
          getline(file, author)) {
        count++;
    }

    file.close();

    cout << "Total Books: " << count;
}

// ---------------- MAIN ----------------
int main() {
    Library obj;
    obj.login();
    return 0;
}
