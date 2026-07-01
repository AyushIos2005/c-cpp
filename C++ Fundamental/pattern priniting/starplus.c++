#include<iostream>
using namespace std;
 int  main(){
    int n;
    cout<<"Enter the number of lines:-";
    cin>>n;
    int a;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            a =n/2+1;
            if(i==a||j==a){
                cout<<"* ";
            }else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
 }