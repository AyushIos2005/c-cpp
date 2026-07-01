#include<iostream>
using namespace std;
void num(int n,int m){
    if(n>m) return;//base
    cout<<n<<endl;
    return num(n+1,m);//call

}
int main(){
    int n;
    cout<<"ENter a number : ";
    cin>>n;
    num(1,n);
}