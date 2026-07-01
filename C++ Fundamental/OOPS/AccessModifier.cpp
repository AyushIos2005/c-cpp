#include<iostream>
using namespace std;
class Student{
    public:
    int rollno;
    string name;
    // int age;
    Student(){

    }
   Student(int rollno, string name, int marks){
    this->rollno=rollno;
    this->name=name;
    this->marks=marks;
   }
   void print(){
    cout<<"Name : "<<name<<endl<<"Roll no : "<<rollno<<endl<<"Marks : "<<marks<<endl;//before marks then marks can be asscess..
}

   private:
    int marks;

  
};
// void print(Student s){
    // cout<<"Name : "<<name<<endl<<"Roll no : "<<rollno<<endl<<"Marks : "<<marks<<endl;
// }
 
int main(){
         Student s1(218158,"Ayush Verma",92);
            s1.print();
}