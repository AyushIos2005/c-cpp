#include<iostream>
using namespace std;
    int main(){
        int n;
        cout<<"Enter the number of line : ";
        cin>>n;
        for(int i = 1;i<=n;i++){//for no of rows
                   for(int j=n;j>= n-i+1 ;j--){//for no of colums
                    cout<<j<<" ";
                   }
                   cout<<endl;
        }
        

    }