#include<iostream>
#include<fstream>
using namespace std;

class temp {
    string rollno, name, Fname, Add, Search;
    fstream file;

public:
    void addstudent();
    void viewstudents();
    void searchstudent();
    void deletestudent();
    void countstudents();
};

void temp::addstudent() {
    cout << "Enter Roll No: ";
    cin >> rollno;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Father's Name: ";
    getline(cin, Fname);
    cout << "Enter Address: ";
    getline(cin, Add);

    file.open("Students.txt", ios::out | ios::app);
    file << rollno << "*" << name << "*" << Fname << "*" << Add << endl;
    file.close();

    cout << "\n✔ Student Added Successfully!\n";
}

void temp::viewstudents() {
    file.open("Students.txt", ios::in);
    if (!file) {
        cout << "\nNo Records Found!" << endl;
        return;
    }

    cout << "\n📘 Student Records:\n";

    while (getline(file, rollno, '*') &&
           getline(file, name, '*') &&
           getline(file, Fname, '*') &&
           getline(file, Add)) {
        cout << "Roll No: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Father's Name: " << Fname << endl;
        cout << "Address: " << Add << endl;
        cout << "-----------------------" << endl;
    }
    file.close();
}

void temp::searchstudent() {
    cout << "Enter Roll No to search: ";
    cin >> Search;

    file.open("Students.txt", ios::in);
    bool found = false;

    while (getline(file, rollno, '*') &&
           getline(file, name, '*') &&
           getline(file, Fname, '*') &&
           getline(file, Add)) {
        if (rollno == Search) {
            cout << "\n🎯 Student Found:\n";
            cout << "Roll No: " << rollno << endl;
            cout << "Name: " << name << endl;
            cout << "Father's Name: " << Fname << endl;
            cout << "Address: " << Add << endl;
            found = true;
            break;
        }
    }
    file.close();

    if (!found) cout << "\n Student Not Found!\n";
}

void temp::deletestudent() {
    cout << "\nEnter Roll No to Delete: ";
    cin >> Search;

    file.open("Students.txt", ios::in);
    fstream tempFile;
    tempFile.open("Temp.txt", ios::out);

    bool found = false;

    while (getline(file, rollno, '*') &&
           getline(file, name, '*') &&
           getline(file, Fname, '*') &&
           getline(file, Add)) {
        if (rollno != Search) {
            tempFile << rollno << "*" << name << "*" << Fname << "*" << Add << endl;
        } else {
            found = true;
        }
    }

    file.close();
    tempFile.close();
    remove("Students.txt");
    rename("Temp.txt", "Students.txt");

    if (found)
        cout << "\n Student Deleted Successfully!\n";
    else
        cout << "\n Student Not Found!\n";
}

void temp::countstudents() {
    file.open("Students.txt", ios::in);
    if (!file) {
        cout << "\n Total Students: 0\n";
        return;
    }

    int count = 0;
    while (getline(file, rollno, '*') &&
           getline(file, name, '*') &&
           getline(file, Fname, '*') &&
           getline(file, Add)) {
        count++;
    }

    file.close();
    cout << "\n Total Students: " << count << endl;
}

int main() {
    temp object;
    int choice;

    while (true) {
        cout << "\n===== Student Management System =====\n";
        cout << "1-Add Student\n";
        cout << "2-View Students\n";
        cout << "3-Search Student\n";
        cout << "4-Delete Student\n";
        cout << "5-Count Students\n";
        cout << "6-Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: object.addstudent(); break;
        case 2: object.viewstudents(); break;
        case 3: object.searchstudent(); break;
        case 4: object.deletestudent(); break;
        case 5: object.countstudents(); break;
        case 6: cout << "Exiting..."; exit(0);
        default: cout << "Invalid Choice!" << endl;
        }
    }
}
