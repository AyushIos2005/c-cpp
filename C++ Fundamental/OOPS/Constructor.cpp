#include<iostream>
 using namespace std;
 class Student{//Student class definition by me..
    public:
    string name;
    int roll;
    float marks;

    //construct
    Student( string s, int r, float m){
        name=s;
        roll=r;
        marks=m;
    }
};
 int main(){
     Student s1("Ayush Verma",76,8.2);

    //  s1.name="Ayush Verma";
     
    //  s1.marks=90.0;
    //  cout<<"Enter Roll no : ";
    //  cin>>s1.roll;
     
      cout<<s1.name<<" "<<s1.roll<<" "<<s1.marks<<" "<<endl;
    // Student s2;
    //  s2.name="Ayush Verma";
    //  s2.roll=5;
    //  s2.marks=95.0;
    //  cout<<s2.name<<" "<<s2.roll<<" "<<s2.marks<<" "<<endl;
    
}