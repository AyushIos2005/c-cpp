#include<iostream>
#include<cmath>
 using namespace std;
 int main(){
    cout<<"Checking of three digit value is armstrong or not\n";
    
   int  arr[3];
   cout<<"Enter the three digit number : ";
   for(int i=0;i<3;i++){
    cin>>arr[i];
   }
   int y = 0;
   int oringal = (arr[0]*100)+(arr[1]*10)+(arr[2]);
   y=y+pow(arr[0],3)+pow(arr[1],3)+pow(arr[2],3);
   if(y==oringal){
    cout<<" Armstrong number \n";
   }
   else{
    cout<<"Not an armstrong number \n";
   }

 }