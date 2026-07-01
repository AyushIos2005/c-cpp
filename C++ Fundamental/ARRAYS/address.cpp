#include<iostream>
 using namespace std;
 int main(){
    int arr[5]={1,2,3,4,5};
    int dum=0;
    for(int i=0;i<5;i++){
        dum=dum+arr[i];
    }
    cout<<"Sum of array : "<<dum;
 }