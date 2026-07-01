//student database by teacher for school...
#include<iostream>
 using namespace std;
 class Student{
    public:
    string name;
    int rollno;
    int standard;
    int idno;

    void taking(int i){
        cout<<"\nEnter a detail of student "<<i+1<<":-\n";
        cout<<"Enter a name of student :";
        cin.ignore();
    getline(cin,name);
    cout<<"Enter a roll number of student :";
    cin>>rollno;
    cout<<"Enter a class of student : ";
    cin>>standard;
    cout<<"Enter a Id number of student : ";
    cin>>idno;
        }
    


    void print(int i){//revese call for print data of student.
        
    cout<<"Student Detail "<<i+1<<":-\n\n"<<"Name of Student :"<<name<<endl<<"Roll no :"<<rollno<<endl<<"Class :"<<standard<<endl<<"ID number :"<<idno<<endl;
  }
 };
  void printthank(){
    cout<<"Successful Student Data is Stored";
  }

 int main(){
     int n;
     cout<<"How many student to add in database: ";
     cin>>n;
     Student s[n];
     for(int i=0;i<n;i++){
        s[i].taking(i);
     }
    cout<<"-----------------------------------------------------------------\n";
    for(int i=0;i<n;i++)
        s[i].print(i);
    //si.print();//call for printing data 
    cout<<"-------------------------------------------------------------------\n";
    printthank();//printing succesful message ..

 }//code completeed....