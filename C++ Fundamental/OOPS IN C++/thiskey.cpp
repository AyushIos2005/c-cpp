#include<iostream>
 using namespace std;
 class cricketer{
     public :
     string name;
     int runs;
     cricketer(string n,int r){
        this->name = n;
        this->runs=r;
     }
     void print(int runs){
        cout<<this->name<<" "<<this->runs<<endl;
     }

 };
 /*void print(cricketer c){//we can wrt in class
    cout<<c.name<<" "<<c.runs<<endl;*/
 //}
 int main(){
    cricketer c1("Virat",25000);
    cricketer c2("Rohit",52000);
    
    //cout<<c1.name<<" "<<c1.runs<<endl;
    //cout<<c2.name<<" "<<c2.runs<<endl;
    c1.print(5);   
    c2.print(5);

 }