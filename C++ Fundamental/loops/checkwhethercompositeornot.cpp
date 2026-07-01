#include<iostream>
 using namespace std;
 int main() {   
    int n;
    cout << "Enter any number: ";
    cin >> n;
    bool x = true;//number is prime
    for(int i = 2; i <= n / 2; i++) {
        if(n % i == 0) {
            x = false;//false mean composite
            cout << n << " is a composite number." << endl;
            break; // Exit the program if a factor is found
        }


    }
    if (x == true){
        cout<<" Prime Number."<<endl;

    } else if (n==1){
        cout<<"Nethier prime nor composite number."<<endl;
    }
    else{
        cout<<"Composite Number."<<endl;
    }

    return 0; 
}