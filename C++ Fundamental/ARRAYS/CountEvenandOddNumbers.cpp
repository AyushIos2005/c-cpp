#include<iostream>
 using namespace std;
 int main(){
        int n;
        cout<<"Enter the number of elment : ";
        cin>>n;
        int yellow[n];
        cout<<"Enter the of elment : ";
        for(int i =0;i<n;i++){
            cin>>yellow[i];
        }
        int evenCount = 0, oddCount = 0;
        for(int i = 0;i<n;i++){
            if(yellow[i]%2==0) evenCount++;
            else oddCount++;
        }
        cout<<"Count of Even Numbers : "<<evenCount<<endl;
        cout<<"Count of Odd Numbers : "<<oddCount<<endl;
 }//success.