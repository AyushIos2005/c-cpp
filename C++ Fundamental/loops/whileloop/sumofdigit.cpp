#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the number of element  : ";
    cin>>n;
    int sum = 0;
    int num;
    for(int i = 1;i<=n;i++){
        cout<<"Enter the number "<<i<<":";
        cin>>num;
        sum=sum+num;
    }
    cout<<"Sum of the number = "<<sum<<endl;
    
 }
 //ayush verma method 