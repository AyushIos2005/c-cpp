//changer-1{print (n to 1) n take by user}
#include<iostream>
using namespace std;
int number(int y){
    if(y==1) return 1;
    cout<<y<<endl;

    return number(y-1);
}
int main(){
    int n;
    cout<<"Enter the any number : ";
    cin>>n;
    cout<<number(n)<<endl;
}//complete change .