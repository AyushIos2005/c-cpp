#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter a number of element  :";
    cin>>n;
    int yum[n];
    cout<<"Enter the number of element : ";
    for(int i=0;i<n;i++){
        cin>>yum[i];

    }
    int sum=0;
    cout<<"sum of element are :";
    for(int i=0;i<n;i++){
        sum=sum+yum[i];

    }
    cout<<" "<<sum;


}