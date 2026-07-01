#include<iostream>
 using namespace std;
 int main(){
     int n;
     cout<<"Give a number : ";
      cin>>n;
     if(n%5 == 0){
        
        cout<<n<<" is divisible by 5 ."<<endl;
        cout<<"Thank you!!"<<endl;
     } else{

        cout<<n<<" is not diviblse by 5."<<endl;

     }
    return 0;
 }