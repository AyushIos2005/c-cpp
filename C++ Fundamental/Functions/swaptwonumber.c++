#include<iostream>
using namespace std;
int swap(int* x, int* y) {//passing by refecrence
    
    // This function swaps the values of x and y using arithmetic operations.
    // Swapping using arithmetic operations
    *x = *x + *y; // Step 1: Add both numbers
    *y = *x - *y; // Step 2: Subtract the new value of 'x' with 'y' to get original 'x'
    *x = *x - *y; // Step 3: Subtract the new value of 'y' from 'x' to get original 'y'
    return 0;
}
int main() {
    int a, b;
    cout << "Enter first number: ";
    cin >> a;
    cout << "Enter second number: ";
    cin >> b;

    // Swapping using arithmetic operations
    //a = a + b; // Step 1: Add both numbers
    //b = a - b; // Step 2: Subtract the new value of 'a' with 'b' to get original 'a'
    //a// = a - b; // Step 3: Subtract the new value of 'b' from 'a' to get original 'b'
    swap(&a,&b);
    cout << "After swapping: " << endl;
    cout << "First number: " << a << endl;
    cout << "Second number: " << b << endl;

    return 0;
}