//n=4
//1
//01
///101
//0101
#include<iostream>
using namespace std;
 int main(){
    int a;
    cout<<"Enter number of line :- ";
    cin>>a;
    int as=1;
    for(int i =1;i<=a;i++){//no of row
        for(int j=1;j<=i;j++){//no of column
            if((i+j)%2==0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
 }