#include<iostream>
 using namespace std;
 int main(){
    int n;
    cout<<"Enter the number of elemnt (leaving 0): ";
    cin>>n;
    int num;
    int mul; 
   
    for(int i=1;i<=n;i++){
        cout<<"Enter the numebrer  "<<i<<":";
    cin>>num;
        if(num == 0){
            cout<<"Multiplication of digit is 0"<<endl;
            // Exit if zero is encountered
        }
        if(i == 1){
            mul = num; // Initialize multiplication with the first number
        } else {
            mul *= num; // Multiply subsequent numbers
        }        
    }
    cout<<"Multiplication of the digit is "<<mul<<endl;
 }