#include <iostream>
#include <climits> // For INT_MIN
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Step 1: Initialize
    int first = INT_MIN;
    int second = INT_MIN;

    // Step 2: Traverse array
    for(int i = 0; i < n; i++) {
        if(arr[i] > first) {
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second && arr[i] != first) {
            second = arr[i];
        }
    }

    // Step 3: Output
    if(second == INT_MIN)
        cout << "No second largest element (all elements are same or less than 2 unique values)." << endl;
    else
        cout << "Second largest = " << second << endl;

    return 0;
}
