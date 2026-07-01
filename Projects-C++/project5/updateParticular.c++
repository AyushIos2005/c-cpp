#include<bits/stdc++.h>
using namespace std;
int main(){
    
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
    float newAmount;
    cout << "Enter Your Account Number to Update Amount : ";
    cin>>search;
    cout << "Enter New Amount to Deposit : ";
    cin >> newAmount;
    fstream file,file1;
    file.open("BankData.txt",ios::in);
    file.open("data1.txt",ios::out|ios::app);

    file>>accNum>>name>>Fname>>cnic>>P_no>>email>>amount;
    while(!file.eof()){
        if(accNum==search){
            cout<<"Your Previous Amount is : "<<amount<<endl;

            amount=amount+newAmount;
            cout<<"Your Updated Amount is : "<<amount<<endl;
            file1<<accNum<<" "<<name<<" "<<Fname<<" "<<cnic<<" "<<P_no<<" "<<email<<" "<<amount<<endl;
        }
        else{
            file1<<accNum<<" "<<name<<" "<<Fname<<" "<<cnic<<" "<<P_no<<" "<<email<<" "<<amount<<endl;
        }
        file>>accNum>>name>>Fname>>cnic>>P_no>>email>>amount;
    }
    file.close();
    file1.close();
    remove("BankData.txt");
    rename("data1.txt","BankData.txt");
    return 0;
    
}