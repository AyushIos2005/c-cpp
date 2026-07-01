#include<iostream>
 using namespace std;
 int main(){
    cout<<"Enter the 3 x 3 martics : ";
    int arr[3][3];
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }
    cout<<"Here the martice is :- \n";
    for(int i = 0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
     }
      cout<<endl<<"The transpose of martics is \n";
        for(int j =0;j<3;j++){
            for(int i = 0;i<3;i++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        
    
 }
 