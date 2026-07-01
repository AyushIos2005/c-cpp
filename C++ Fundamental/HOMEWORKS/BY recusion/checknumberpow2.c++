//Check a number is power of two.....
#include<iostream>
#include<cmath>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter any number : ";
    cin>>n;
    if(sqrt(n)==pow(n,2)){
        cout<<"Yes!"<<endl;
    }
    else cout<<"no"<<endl;
 }//not solve 