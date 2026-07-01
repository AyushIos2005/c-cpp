#include<iostream>
 using namespace std;
    int main(){
        int a ,b ,c;
         cout<<"Enter the 1st number : ";
         cin>>a;
         cout<<"Enter the 2nd number : ";
         cin>>b;
         cout<<"Enter the 3rd number : ";
         cin>>c;
         // Check which number is the greatest by nested if -else.
         if(a>c){
            if(a>b){
                cout<<a<<" is the greatest number."<<endl;
            }
            else{
                cout<<b<<" is the greatest number."<<endl;
            }
         } else{
            if(c>b){
                cout<<c<<" is the greatest number."<<endl;
            }
            else{
                cout<<b<<" is the greatest number."<<endl;
            }
         }
        return 0;
    }