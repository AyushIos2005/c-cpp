//0 1 1 2 3  5 8 13 21 34 for term n=10
#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the number of terms :  ";
    cin>>n;
    int a,b,c;
    a=0;
    b=1;
    c;
    for(int i = 1;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
        cout<<"The term "<<i<<"are "<<c-a<<endl;
    }

 }