#include<iostream>
using namespace std;
class student{// student is anew data type.
    public:
      string name;
      int roll;
      float cgpa;
      //int marks[]
};
int main(){
  student s1;
  s1.name="Ayush Verma";
  s1.roll=48;
  s1.cgpa=7.78;

  student s2;
  s2.name="Ayush Verma";
  s2.roll=56;
  s2.cgpa=8.9;
  cout<<s1.name<<endl;
  cout<<s2.cgpa<<endl;

}
 