/*
    Problem statment
Create a  Bank Data Mangemnet system , in which multiplr user can create account and Manipulate the data such as Deposite amount , Withdrawal amount , check Previous MAount , Check Profile info and Delete account.

Note : some type of Password or account number for data protection.

*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Welcome to Verma's Bank";
    cout<<"Your Trusted Bank Partner";
    int accNum;
    char name[25];
    char Fname[25];
    char cnic[25];
    char P_no[25];
    char email[25];
    float amount;

    srand(time(0));
    accNum = rand()*rand()+rand()*rand();
    
    cout<<"\n Please Enter Your Name : ";
    cin.getline(name,25);
    cout<<"\n Please Enter Your Father's Name : ";
    cin.getline(Fname,25);
    cout<<"\n Please Enter Your CNIC Number : ";

    cin.getline(cnic,25);
    cout<<"\n Please Enter Your Phone Number : ";
    cin.getline(P_no,25);
    cout<<"\n Please Enter Your Email Address : ";
    cin.getline(email,25);
    cout<<"\n Enter Your Amount : ";
    cin>>amount;

    cout<<accNum<<"is Your Account Number"<<endl;
    cout<<"Please Save it"<<endl;

    fstream file;
    // file<<"A/c"<<"\t"<<"Name"<<"\t"<<"F.Name"<<"\t"<<"CNIC"<<"\t"<<"Phone"<<"\t"<<"Email"<<"\t"<<"Amount"<<endl;

    file.open("BankData.txt",ios::out|ios::app);
    file<<"A/c"<<"\t"<<"Name"<<"\t"<<"F.Name"<<"\t"<<"CNIC"<<"\t"<<"Phone"<<"\t"<<"Email"<<"\t"<<"Amount"<<endl;
    file<<accNum<<"\t"<<name<<"\t"<<Fname<<"\t"<<cnic<<"\t"<<P_no<<"\t"<<email<<"\t"<<amount<<endl;
    file.close();

}
