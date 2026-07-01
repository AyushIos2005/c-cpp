#include<iostream>
 using namespace std;
    int main(){
        int a,b,c;
        cout<<"Enter 1st side of triangle : ";
        cin>>a;
        cout<<"Enter 2nd side of triangle : ";
        cin>>b;
        cout<<"Enter 3rd side of triangle : ";
        cin>>c;
        // Check if the sides can form a triangle
         if((a + b) > (c) && (a + c) > (b) && (b + c) > a){
            cout<<"The sides can be make triangle."<<endl;

         } else{
            cout<<"The sides cannot make triangle."<<endl;

         }

    return 0;
    }