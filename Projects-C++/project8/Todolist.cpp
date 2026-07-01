#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

class Todo {
public:
    int id;
    string task;
    void add_task();
    void show_task();
    void delete_task();
    void update_task();
};

Todo t;
int ID = 0;

// Function to load last used ID from file at start
void load_ID() {
    ifstream fin("todo.txt");
    int tempID;
    string tempTask;
    while (fin >> tempID) {
        getline(fin, tempTask);
        ID = tempID; // always store last ID
    }
    fin.close();
}

void Todo::add_task() {
    system("cls");
    cout << "\nEnter New Task: ";
    cin.ignore();
    getline(cin, task);

    ID++;
    ofstream fout("todo.txt", ios::app);
    fout << ID << " " << task << "\n";
    fout.close();

    cout << "\nTask Added Successfully!\n";
    Sleep(1000);
    system("cls");
}

void Todo::show_task() {
    system("cls");
    ifstream fin("todo.txt");

    cout << "\n========== Your TODO List ==========\n";
    bool empty = true;

    while (fin >> id) {
        getline(fin, task);
        cout << id << " : " << task << endl;
        empty = false;
    }
    fin.close();

    if (empty)
        cout << "\n( No Tasks Found )\n";
    
    cout << "\nPress any key to continue...";
    getch();
    system("cls");
}

void Todo::delete_task() {
    system("cls");
    show_task();

    int delID;
    cout << "\nEnter Task ID to Delete: ";
    cin >> delID;

    ifstream fin("todo.txt");
    ofstream fout("temp.txt");

    bool found = false;

    while (fin >> id) {
        getline(fin, task);
        if (id != delID) {
            fout << id << task << "\n";
        } else {
            found = true;
        }
    }
    fin.close();
    fout.close();

    remove("todo.txt");
    rename("temp.txt", "todo.txt");

    if (found)
        cout << "Task Deleted Successfully!\n";
    else
        cout << "Task ID Not Found!\n";

    Sleep(1000);
    system("cls");
}

void Todo::update_task() {
    system("cls");
    show_task();

    int updateID;
    cout << "\nEnter Task ID to Update: ";
    cin >> updateID;

    cout << "Enter New Task: ";
    cin.ignore();
    getline(cin, task);

    ifstream fin("todo.txt");
    ofstream fout("temp.txt");

    bool updated = false;

    while (fin >> id) {
        string oldtask;
        getline(fin, oldtask);

        if (id == updateID) {
            fout << id << " " << task << "\n";
            updated = true;
        } else {
            fout << id << oldtask << "\n";
        }
    }
    fin.close();
    fout.close();

    remove("todo.txt");
    rename("temp.txt", "todo.txt");

    if (updated)
        cout << "Task Updated Successfully!\n";
    else
        cout << "Task ID Not Found!\n";

    Sleep(1000);
    system("cls");
}

int main() {
    load_ID(); // Load last ID on start

    int choice;
    while (true) {
        cout << "=============================================" << endl;
        cout << "\t\t   MY TODO LIST APP" << endl;
        cout << "=============================================" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Show Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Update Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice) {
        case 1: t.add_task(); break;
        case 2: t.show_task(); break;
        case 3: t.delete_task(); break;
        case 4: t.update_task(); break;
        case 5:
            cout << "\nExiting...";
            for(int i =10;i>=1;i--)
                Sleep(1000);
            exit(0);
        default:
            cout << "Invalid Choice!" << endl;
            for(int i = 5;i>=1;i--)
                Sleep(1000);
            system("cls");
        }
    }
    return 0;
}
