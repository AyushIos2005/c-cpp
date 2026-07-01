#include<iostream>
 using namespace std;
  int main(){
    int n;
    cout <<"Enter a number : ";
    cin >> n;
    // Check if the number is a 3-digit number
    if (n >=100 and n<=999){
        cout<<"3 digit number";
    }
    else{
        cout<<"Not a 3 digit number";
    }
    return 0;
  }