#include<iostream>
#include<string>
 using namespace std;
 class tecaher{
    //property
    private:
    int salary;
    public:
   /*tecaher(){
        dept = "computer science";
    }//non parametresized costurtotr*/
    tecaher(string n,string d, string s, int sal){//parametreixed
        name = n;
        dept = d;
        subject = s;
        salary = sal;
    } 
    string name;
    string dept;
    string subject;
  
    //methodorfunction
   
    
    void getinfo(){
        cout<<"name : "<<name<<endl;
        cout<<"Subject : "<<subject<<endl;
    }
};
 

 int main(){
  tecaher t1("Ayush","Computer science","C++",50000);
  // t1.getinfo();
    tecaher t2(t1);
     t2.getinfo();

 }