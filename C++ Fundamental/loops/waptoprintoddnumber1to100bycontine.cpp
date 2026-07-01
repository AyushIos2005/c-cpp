#include<iostream>
 using namespace std;
  int main(){
    int n=100;
    cout << "Odd numbers from 1 to " << n << " are:\n";

    for(int i =1;i<=n;i++){
        if(i % 2 == 0) continue;
        cout <<i<<"\t";
    }
  }