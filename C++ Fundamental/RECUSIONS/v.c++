//print n to 1;
//using recusion
#include<iostream>
using namespace std;
void call(int y){
    if(y==0) return;//basenbhdn case stoppage 
    
    cout<<y<<endl;
    return call(y-1);
}
 
 int main(){
    int n = 6;
    call(n);
 }