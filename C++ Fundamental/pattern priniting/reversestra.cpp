#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"ENTER OF LINES : ";
    cin>>n;
    for (int i= 1;i<=n;i++){//for no of row
        for(int j = n;j>=i;j--){//for no of column
            cout<<"* ";
        }
        cout<<endl;
    }
 }