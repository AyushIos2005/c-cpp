#include<iostream>
 using namespace std;
  int main(){
    int n;
    cout<<"Enter the number of element : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the element : ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }   
    // Step 1: Swap first and last digits
    int temp = arr[0];
    arr[0]=arr[n-1];
    arr[n-1] = temp;
    // Step 2: Output the modified array
    cout<<"The modified array is : ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
    
  }