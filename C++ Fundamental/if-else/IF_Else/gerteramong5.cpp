#include<iostream>
 using namespace std;
  int main(){
    int a, b, c, d, e;
     cout << "Enter 1st number: ";
        cin>>a; 
            cout<<"Enter 2nd number :";
             cin>>b;
              cout<<"Enter 3rd number :";
               cin>>c;
                cout<<"Enter 4th number :";
                 cin>>d;
                  cout<<"Enter 5th number :";
                   cin>>e;
              // Check which number is the greatest among 5 numbers
    if(a >= b && a >= c && a >= d && a >= e) {
        cout<<a<<"is the greatest number."<<endl;
    }
    else if(b >= a && b >= c && b >= d && b >= e) {
        cout<<b<<" is the greatest number."<<endl;
    }
    else if(c >= a && c >= b && c >= d && c >= e) {
        cout<<c<<" is the greatest number."<<endl;
    }
    else if(d >= a && d >= b && d >= c && d >= e) {
        cout<<d<<" is the greatest number."<<endl;
    }
    else {
        cout<<e<<" is the greatest number."<<endl;
    }     
    return 0;
  }