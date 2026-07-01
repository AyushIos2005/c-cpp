#include<iostream>
#include<cmath>
#include<string>
#include<cstdlib>
using namespace std;

string getpassword(int length){
  string Pass = "";
  string character = "aqwertyuiopsdfghjklzxcvbnm123456789/*-+!@#$%^&*(){}[]";
  int charlen = character.length();
  int randidx;
   for(int i = 0;i<length;i++){
        randidx = rand()%charlen;
        Pass += character[randidx];
   }
   return Pass;
}
int main(){
  int length;
  cout<<"Enter the length of Password : ";
  cin>>length;
  string password = getpassword(length);
    cout<<"Your Password is : "<<password<<endl; 
    return 0;
}