#include<iostream>
using namespace std;
class Scooty{
    public:
  int topSpeed;
  float milage;

   void sound(){
    cout<<"Vroom Vroom"<<endl;
   }
 private:
  int bootSpace; 
};
class Bike:public Scooty{
    public:
    int gears;
    void sound(){
        cout<<"Dhroom Dhroom"<<endl;
    }
};

int main(){
    Bike* b=new Bike();
    b->gears=9;
   Scooty* s=new Scooty();
    s->sound();
    cout<<b->gears<<endl;
 }