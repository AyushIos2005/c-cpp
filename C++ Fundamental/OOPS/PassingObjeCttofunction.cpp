#include<iostream>
using namespace std;
class Car{
 public:
    string name;
    int price;
    int seats;
    string type;


};
void print(Car c1){
     cout<<"Name of car is : "<<c1.name<<endl<<"Price of car : "<<c1.price<<endl<<"Seat capacity of car : "<<c1.seats<<endl<<"Type of car : "<<c1.type<<endl;
}
void change(Car &c){
    c.name="Audi"; 
}
int main(){
    // int t=4;
    // cout<<t<<endl;
    // change(t);
    // cout<<t<<endl;

    Car c1;
    c1.name="BMW";
    c1.price=198000;
    c1.seats=8;
    c1.type="SUV";
    // cout<<"Name of car is : "<<c1.name<<endl<<"Price of car : "<<c1.price<<endl<<"Seat capacity of car : "<<c1.seats<<endl<<"Type of car : "<<c1.type<<endl;
    Car c2;
    c2.name="BMW";
    c2.price=198000;
    c2.seats=8;
    c2.type="Mango DB";
    
    print(c1);

    cout<<endl;
    cout<<endl;
    change(c2);
    print(c2);

}