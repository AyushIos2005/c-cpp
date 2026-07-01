#include<bits/stdc++.h>
using namespace std;
class Area{
   double r,l,b,h,a;
   public:
   void Area_Circle(){
    cout<<"Enter the radius of Circle : ";
    cin>>r;
    a=3.14*r*r;
    cout<<"Area of Circle is : "<<a<<endl;
   } 
   void Area_Rectangle(){
    cout<<"Enter the length and breadth of Rectangle : ";
    cin>>l>>b;
    a=l*b;
    cout<<"Area of Rectangle is : "<<a<<endl;
   }
    void Area_Triangle(){
    cout<<"Enter the height and base of Triangle : ";
    cin>>h>>b;
    a=0.5*h*b;
    cout<<"Area of Triangle is : "<<a<<endl;

    }
    void Area_Square(){
    cout<<"Enter the side of Square : ";
    cin>>a;
    a=a*a;
    cout<<"Area of Square is : "<<a<<endl;

    }
    void Area_Sphere(){
    cout<<"Enter the radius of Sphere : ";
    cin>>r;
    a=4*3.14*r*r;
    cout<<"Area of Sphere is : "<<a<<endl;

    }
    void Area_Cylinder(){
    cout<<"Enter the radius and height of Cylinder : ";
    cin>>r>>h;
    a=2*3.14*r*h+2*3.14*r*r;
    cout<<"Area of Cylinder is : "<<a<<endl;

    }
    void Area_Cone(){
    cout<<"Enter the radius and slant height of Cone : ";
    cin>>r>>h;
    a=3.14*r*(r+h);
    cout<<"Area of Cone is : "<<a<<endl;

    }

};
int main(){
    Area object;
    int choice;
    cout<<"Press 1 for Area of Circle "<<endl;
    cout<<"Press 2 for Area of Rectangle"<<endl;
    cout<<"Press 3 for Area of Triangle"<<endl;
    cout<<"Press 4 for Area of Square"<<endl;
    cout<<"Press 5 for Area of Sphere"<<endl;
    cout<<"Press 6 for Area of Cylinder"<<endl;
    cout<<"Press 7 for Area of Cone"<<endl;
    cout<<"Press 8 for Exit"<<endl;
  while(1){
    cout<<"Enter Your Choice : ";
    cin>> choice;
    switch (choice)
    {
    case 1:  object.Area_Circle();break;
    case 2: object.Area_Rectangle(); break;
    case 3: object.Area_Triangle(); break;
    case 4: object.Area_Square(); break;
    case 5: object.Area_Sphere(); break;
    case 6: object.Area_Cylinder(); break;
    case 7: object.Area_Cone(); break;
    case 8 :cout<<"Exiting.....!!!"; exit(0); break;

    default:cout<<"Something went Worng.....!";break;
    }
}
    return 0;
}