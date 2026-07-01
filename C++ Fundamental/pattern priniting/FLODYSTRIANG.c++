#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the number of line :- ";
    cin>>n;
    int ad=1;
    for(int i = 1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<ad;
            ad++;
        }
        cout<<endl;
    }
 }