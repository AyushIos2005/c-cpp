#include<iostream>
#include<cmath>
using namespace std;
 int main(){
        int n;
        cout<<"Enter the number of elements: ";
        cin>>n;
        int arr[n];
        cout<<"Enter the elements: ";
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        
        int maxElement = arr[0];
        int minElement = arr[0];
        
        for(int i = 1; i < n; i++){
            if(arr[i] > maxElement) maxElement = arr[i];
            if(arr[i] < minElement) minElement = arr[i];
        }
        
        cout<<"Maximum Element: "<<maxElement<<endl;
        cout<<"Minimum Element: "<<minElement<<endl;
        
        return 0;

 }//chanelleged solvred.