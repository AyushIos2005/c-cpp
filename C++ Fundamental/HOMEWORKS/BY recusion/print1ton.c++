////changer-2{print (1to n) n take by user}
#include<iostream>
 using namespace std;
 int number(int y){
     if(y==1) return 1;
     
     number(y - 1);
     cout<<y<<endl;
 }
 int main(){
    int n;
    cout<<"Enter the any number : ";
    cin>>n;
    cout<<number(n)<<endl;
 }
//change-not 