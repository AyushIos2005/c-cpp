//n=4
//ABCD
//ABCD
//ABCD
//ABCD
#include<iostream>
 using namespace std;
 int main(){
    int n;
     cout<<"Enter the number of line :";
     cin>>n;
     for(int i=1;i<=n;i++){
        int ay=1;
        for(int j=1;j<=n;j++){
            int d = ay+64;
            char ch = (char)d;//typecasting


            cout<<ch<<" ";
            ay++;
        }
        cout<<endl;
     }

 }