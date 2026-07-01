#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the number of lines : ";
    cin>>n;
    for(int i = 1;i<=n;i++){//rows ke liye
        //3
        //cout<<i<<" " ;
        for(int j = 1;j<=n;j++ ){//columns ke liye
            cout<<i<<" ";

        }
        cout<<endl;
    }
    
 }