#include<iostream>
using namespace std;
int sum(int y){
    if(y==0) return 0;//base case
    cout<<y<<endl;
    return y+sum(y-1);//return recurssive function

}
int main(){
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    /*int sum = 0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
        //cout<<"Sum : "<<i<<endl;
    }*/
    cout<<"Sum : "<<sum(n)<<endl;
}