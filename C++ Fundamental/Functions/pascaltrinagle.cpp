//pascal triangle
#include<iostream>
 using namespace std;
 int comb(int u){
    int g=1;
    for(int i=1;i<=u;i++){
        g=g*i;
    }
    return g;
 }
 int main(){
    int n;
    cout<<"Enter the number of line : ";
    cin>>n;
    //int b;
    for(int i = 0;i<=n;i++){
        for(int k=0;k<n-i+1;k++){
            cout<<" ";
        }
        for(int j=0;j<=i;j++){
          cout<<comb(i)/(comb(j)*comb(i-j))<<" ";  
        
        }
        cout<<"\n";
    }
    
 }
