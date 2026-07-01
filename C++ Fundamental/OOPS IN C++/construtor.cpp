#include<iostream>
using namespace std;
class student{// student is anew data type.
    public:
      string name;
      int roll;
      float cgpa;
      //int marks[]


      student(string s,int r,float g){//communctor
        name=s;
        roll=r;
        cgpa=g;

      }      
};
int main(){
  student s1("Ayush verma",98,9.9);
  /*s1.name="Ayush Verma";
  s1.roll=48;
  s1.cgpa=7.78;*/

 /*student s2;
  s2.name="Ayush Verma";
  s2.roll=56;
  s2.cgpa=8.9;*/
  cout<<s1.name<<endl<<s1.roll<<endl<<s1.cgpa<<endl;
 // cout<<s2.cgpa<<endl;

}
 