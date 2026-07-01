#include<iostream>
using namespace std;

void reversePrint(int n) {
    if(n == 0) return;            // base case
    cout << n % 10 << " ";       // print last digit
    reversePrint(n / 10);         // call on remaining number
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    if(num == 0)
        cout << 0 << endl;        // special case for 0
    else
        reversePrint(num);        // call recursive function

    return 0;
}
