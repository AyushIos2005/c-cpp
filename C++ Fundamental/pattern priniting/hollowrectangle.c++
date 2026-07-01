#include<iostream>
 using  namespace std;
 int main(){
    //rctangle printing
    int n;
    cout<<"Enter the number of rows : ";
    cin>>n;
    int m;
    cout<<"Enter the number of colums : ";
   cin>>m;
    for(int i =1;i<=n;i++){//no of line or rows
        for(int j = 1;j<=m;j++){//no of colums 
            if(i==1||i==n-1|| j==1||j==m-1){
                cout<<"* ";
        }else{
            cout<<"  ";

        }
        cout<<endl;
    }
 }
}