#include<iostream>
 using namespace std;
  int main(){
    int a, b,c;
     cout<<"Enter the 1st number : ";
     cin>>a;
     cout<<"Enter the 2nd number : ";
     cin>>b;
     //make baisc switch case calculator
     char ch;
     cout<<"Enter the operation you want to perform (+, -, *, /): ";
     cin>>ch;
     switch(ch){
        case '+':
             c = a + b;
                cout << "Result: " << c << endl;
                break;
        case '-':
             c = a - b;
                cout << "Result: " << c << endl;
                break;
        case '*':
             c = a * b;
                cout << "Result: " << c << endl;
                break;
        case '/':   
                if(b != 0) {
                    c = a / b;
                    cout << "Result: " << c << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
        default: cout<<"Invalid operation. Please enter one of +, -, *, /." << endl;
                break;
              
     }

    return 0;
  }