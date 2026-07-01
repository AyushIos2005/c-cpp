#include<iostream>
 using namespace std;
 int main(){
    int s,r;
    //s==shyam and r==ram;
    cout<<"Enter age of Ram : ";cin>>r;
    cout<<"Enter age of Shyam  : ";cin>>s;
    //which one is smallest;

    if(r<s){
        cout<<"Ram is YOunger than Shyam"<<endl<<r<<endl<<"Ram"<<endl;
    }
    else{
        cout<<"Shyam is Younger than Ram" <<endl<<s<<endl<<"Shyam"<<endl;
    }
    return 0;
 }