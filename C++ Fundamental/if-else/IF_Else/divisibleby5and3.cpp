#include<iostream>
 using namespace std;
  int main(){
        int n;
        cout<<"GIve a number :";
        cin>>n;
        // Check if the number is divisible by both 5 and 3
        if(n%5==0 || n%3==0){
            cout<<n<<" is divisible by both 5 or 3."<<endl;
            cout<<"Thank you!!"<<endl;
        } else {
            cout<<n<<" is not divisible by both 5 or 3."<<endl;
        }
  }