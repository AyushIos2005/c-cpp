#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << "Welcome to Verma's Bank\n";
    cout << "Your Trusted Bank Partner\n\n";

    int accNum;
    char name[25];
    char Fname[25];
    char cnic[25];
    char P_no[25];
    char email[25];
    float amount;

    int search;
    cout << "Enter Your Account Number to Search : ";
    cin >> search;

    fstream file("BankData.txt", ios::in);
    if(!file) {
        cout << "File Not Found!" << endl;       
    }
    file>>accNum>>name>>Fname>>cnic>>P_no>>email>>amount;
    while(!file.eof()) {
        if(accNum == search) {
            cout << "\n Account Number : " << accNum;
            cout << "\n Name : " << name;
            cout << "\n Father's Name : " << Fname;
            cout << "\n CNIC Number : " << cnic;
            cout << "\n Phone Number : " << P_no;
            cout << "\n Email Address : " << email;
            cout << "\n Amount : " << amount;
        }
        file >> accNum >> name >> Fname >> cnic >> P_no >> email >> amount;
    }
    file.close();
    return 0;
}
