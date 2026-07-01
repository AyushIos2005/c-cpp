#include<iostream>
#include<cmath>     // for sin(), cos(), etc.
using namespace std;

int main(){
    double degree = 90;

    // Convert degrees to radians
    double rad = degree * (M_PI / 180.0);

    // Calculate sine
    double result = sin(rad);

    cout << "sin(" << degree << "°) = " << result << endl;

    return 0;
}
