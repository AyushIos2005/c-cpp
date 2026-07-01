#include<iostream>
#include<climits>
using namespace std;
int main(){
    int arr[5]={1,2,-3,4,5};
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    int t=INT_MIN;
    int smax=INT_MIN;
     for(int i=0;i<5;i++){
        if(t<arr[i]) {
            t=arr[i];
            // t+1;
        }
        if(smax<t && t !=arr[i]){
            smax=arr[i];
        }
    }

    cout<<endl;
    cout<<smax;
}