#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int flag = 0;  //singal

    for(int i = 0; i < n / 2; i++) {
        if(arr[i] != arr[n - i - 1]) {
            flag = 1; // Not a palindrome
            break;
        }
    }

    if(flag == 0)
        cout << "The array is a palindrome " << endl;
    else
        cout << "The array is NOT a palindrome " << endl;

    return 0;
}
