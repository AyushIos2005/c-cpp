#include<iostream>
using namespace std;
int main() {
    int n;
    cout<<"Give a number : ";
    cin>>n;
    //even or odd by using ternary operation;
    //condition ? expression_if_true : expression_if_false
    (n%2==0)?cout<<"even":cout<<"odd";
    

    return 0;
}