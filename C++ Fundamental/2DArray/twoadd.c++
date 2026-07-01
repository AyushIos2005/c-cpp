#include<iostream>
 using namespace std;
 int main(){
    cout<<"Enter the 1st  3 x 3  martics : ";
    int arr[3][3];
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
       /// cout<<endl;
    }
    int brr[3][3];
    cout<<"Enter the 2nd 3 x 3 matric : ";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>brr[i][j];
        }
    }
    cout<<"Here the 1st martice is :- \n";
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"Here the 2nd martice is :- \n";
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    int crr[3][3];
    cout<<"The Sum of matrics : \n";
    for(int i = 0;i<3;i++){
        for(int j =0;j<3;j++){
             crr[i][j]=arr[i][j]+brr[i][j];
            }
            cout<<endl;
    }
    for(int i = 0;i<3;i++){
        for(int j =0;j<3;j++){
             cout<< crr[i][j]<<" ";
            }
            cout<<endl;
    }
    

 }
 