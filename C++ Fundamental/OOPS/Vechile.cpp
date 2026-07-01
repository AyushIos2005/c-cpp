// single level 
#include<iostream>
using namespace std;
class Vehicle{//parent class
    public:
    int topspeed;
    float mileage;
    string fuel;

};
class Car: public Vehicle{
  public:
  bool sunroof;

};
class Scooty: public Vehicle{
    public:
};
class Truck: public Vehicle{
    public:
};

class Bike:public Vehicle{//daughter class
 public:
  int gears;
};
int main(){
  Bike b1;
  b1.topspeed=100;
  b1.mileage=20.0;
  b1.gears=5;
  


}