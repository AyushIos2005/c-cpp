#include<iostream>
using namespace std;
int main() {
    int x = 5;
    cout<<x<<endl;
    x = 10;
    cout<<x<<endl;
    x = 20;
    cout<<x<<endl; // Output the updated value of x
    x = x - 20;
    cout<<x<<"\n";
    x = 90 + x;
    cout<<x<<"\n";
    x = x / 2;
    cout<<x<<"\n"; // Output the final value of x after all updates
    //cout << "Hello, World!" << endl; // Output a greeting message
    return 0; // Indicate that the program ended successfully
}