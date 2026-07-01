#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter a inital number :";
    cin>>n;
    int m;
    cout<<"Enter a final number :";
    cin>>m;
     //loop for even and odd m-1
     for(int i = n;i <= m;i++){
        if(i%2==0){
            cout<<i<<endl;
        }
  
    }
    
 }