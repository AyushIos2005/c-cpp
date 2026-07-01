#include<iostream>
 using namespace std;
  int fabon(int y){
    if(y==1||y==2) return 1;
    return fabon(y - 1)+fabon(y - 2);
  }
     
 int main(){
    int n;
    cout<<"Enter the term : ";
    cin>>n;
    cout<<n<<"Terms\n"<<fabon(n)<<endl;
 }