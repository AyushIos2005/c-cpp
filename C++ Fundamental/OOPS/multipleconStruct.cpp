#include<iostream>
using namespace std;
class Student{
    public:
    string name;
    int rollno;
    float marks;
//Constuctor
 Student(string n,int r,float m){
    name=n;
    rollno=r;
    marks=m;
 }
 

};
int main(){
    Student s1("Ayush verma",62,7.74);
    cout<<s1.name<<" "<<s1.rollno<<" "<<s1.marks<<endl;
    Student s6 = s1;//shollow copy
    s6.name="Kariy";
     cout<<s6.name<<" "<<s6.rollno<<" "<<s6.marks<<endl;
     Student s7(s1);//deep copy
    //  s7.name="Karkit"
     cout<<s7.name<<" "<<s7.rollno<<" "<<s7.marks<<endl;

    }