//write a program to store roll number and marks obtained by 4 student side by sode in a martix.
#include<iostream>
#include<climits>
 using namespace std;
 int main(){
    int arr[4][2]={76,81,13,25,82,91,88,90};
    int mx= INT_MIN;
    for(int i=0;i<4;i++){
        for(int j=0;j<2;j++){
            mx = max(mx,arr[i][j]);
        }
    }
    cout<<endl<<mx;
    
 }