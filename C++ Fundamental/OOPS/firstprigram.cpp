#include<iostream>
#include<string>
using namespace std;
 class Student{//Student class definition by me..
    public:
    string name;
    int roll;
    float marks;
};
class Car{
    public:
    string name;
    int price;
    int seats;
    string type;
};
int main(){
    /* Student s1;
     s1.name="Ayush Verma";
     
     s1.marks=90.0;
     cout<<"Enter Roll no : ";
     cin>>s1.roll;
     
      cout<<s1.name<<" "<<s1.roll<<" "<<s1.marks<<" "<<endl;
    Student s2;
     s2.name="Ayush Verma";
     s2.roll=5;
     s2.marks=95.0;
     cout<<s2.name<<" "<<s2.roll<<" "<<s2.marks<<" "<<endl;*/
    Car c1;
    c1.name="BMW";
    c1.price=198000;
    c1.seats=8;
    c1.type="SUV";
    cout<<"Name of car is : "<<c1.name<<endl<<"Price of car : "<<c1.price<<endl<<"Seat capacity of car : "<<c1.seats<<endl<<"Type of car : "<<c1.type<<endl;
}