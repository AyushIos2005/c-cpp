// single level 
#include<iostream>
using namespace std;
class Scooty{//parent class
    public:
    int topspeed;
    float mileage;
    private:
    int bootSpace;

};
class Bike:public Scooty{//daughter class
 public:
  int gears;
};
int main(){
  Bike b1;
  b1.topspeed=100;
  b1.mileage=20.0;
  b1.gears=5;
//   b1.bootSpace=12;


}