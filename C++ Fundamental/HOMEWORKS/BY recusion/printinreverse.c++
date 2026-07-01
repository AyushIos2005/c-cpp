//Print resevres numbers using recursion
#include<iostream>
 using namespace std;
 int printReverse(int n){
     if(n==0) return 0; //base case
     cout<<n<<endl; //print number
     return printReverse(n-1); //recursive call
 }
 int main(){
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int m[n];
    cout<<"Enter a number : ";
    for(int i=0;i< n;i++)
    cin>>m[i];
        //for revrese....
        for(int i = n - 1 ;i>=0;i--){
            cout<<m[i]<<" ";
        }


 }