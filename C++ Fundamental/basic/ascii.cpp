#include<iostream>
 using namespace std;
  int main(){
    
    char ch;//char to  int
    cin>>ch;
    cout<<(int)ch<<endl;
    int n;//int to char
    cin>>n;
    cout<<(char)n<<endl;
    float b = 7.0/22*(3.14+2)*3.0/5;
    cout<<b<<endl; // This line will cause an error because 'a' is not defined


    return 0;
  }