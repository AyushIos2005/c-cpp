#include<iostream>
using namespace std;
void num(int n){
    if(n==0) return;//base
    //cout<<n<<endl;
   num(n- 1);//call
    cout<<n<<endl;
}
int main(){
    int n;
    cout<<"ENter a number : ";
    cin>>n;
    num(n);
}