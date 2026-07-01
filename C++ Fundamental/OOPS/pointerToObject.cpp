#include<iostream>
 using namespace std;
 class Circket{
    public:
    string name;
    int runs;
    float avg;
    Circket(string name, int runs,float a){
       this-> name=name;
       this-> runs=runs;
       avg=a;
    }
   
};
void change(Circket *c){
   c->runs=100;
}
 int main(){
    Circket c1("Virat",100000,60.5);
    Circket c2("Rohit",502000,90.2);
   cout<<c1.runs<<endl;
   // Circket *p1=&c1;
   change(&c1);
   cout<<c1.runs<<endl; 
  
 }