#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the number of term:";
    cin>>n;
    int sum=0;
    for(int i =1;i<=n;i++){
        if(i%2==0){
            sum=sum+i;

        }
        
    }
    cout<<"Sum of Even number are = "<<sum<<endl;
 }