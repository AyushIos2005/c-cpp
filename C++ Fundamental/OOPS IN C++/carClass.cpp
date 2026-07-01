#include<iostream>
using namespace std;
class car{// student is anew data type.
    public:
      string name;
      int price;
      int seat;
      string type;
      //int marks[]
};
/*void print(car c){//function
    cout<<c.name<<" "<<c.price<<" "<<c.seat<<" "<<c.type<<" "<<endl;
}*/
void change(int x){
      x=109;
}
int main(){
    int x=4;
    cout<<x<<endl;
    change(x);
    cout<<x<<endl;
   /* car c1;
    c1.name="Honada city";
    c1.price=1500000;
    c1.seat=8;
    c1.type="suv";
    car c2;
    c2.price=1500000;
    c2.name="Honada";
    c2.seat=6;
    c2.type="Hatchbacks";
    print(c1);
    print(c2);*/
    
  
}