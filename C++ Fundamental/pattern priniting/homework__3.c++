#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the number of lines : ";
    cin>>n;
    for(int i = 1;i<=n;i++){//rows ke liye
        
        //cout<<i<<" " ;
        int ay = 1;
    
        if(i%2!=0)
        {
            for(int j = 1;j<=i;j++ ){//columns ke liye
            cout<<j<<" ";
        }
    }
        else{
            for(int j = 1;j<=i;j++ )
         {
                //columns ke liye
            int d = ay+64;
            char ch = (char)d;//typecasting
            cout<<ch<<" ";
            ay++;
        }
        
        }
        cout<<endl;
    }
    
 }