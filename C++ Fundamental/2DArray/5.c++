#include<iostream>
 using namespace std;
 int main(){
    //cout<<"Enter the 3 x 3 martics : ";
    int arr[5][5];
    for(int i = 0;i<5;i++){
        for(int j=0;j<5;j++){
            arr[i][j]=0;
        }
        cout<<endl;
    }
    cout<<"Here the martice is :- \n";
    for(int i = 0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
 }