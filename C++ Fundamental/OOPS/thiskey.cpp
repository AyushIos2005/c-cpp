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
    void print(){
        cout<<name<<" "<<runs<<" "<<avg<<endl;
    }
    int match(){
        return runs/avg;
    }
};
 int main(){
    Circket c1("Virat",100000,60.5);
    Circket c2("Rohit",502000,90.2);
    c1.print();
    c2.print();
    cout<<"Virat play match : "<<c1.match()<<endl;

    // print(
//    cout<<c1.name<<" "<<c1.runs<<endl;
//    cout<<c2.name<<" "<<c2.runs<<endl;
    
 }