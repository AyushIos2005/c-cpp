//normal method.c ncr=n/r(n-r)
#include<iostream>
 using namespace std;
  int main(){
    int n;
    cout<<"Enter any number n : ";
    cin>>n;
     int r;
    cout<<"Enter any number r : ";
    cin>>r;
    //cout<<n<<"! = ";
    int fact_n=1;
    int fact_r=1;
    int fact_nr=1;
    for(int i = 1;i<=n;i++){
        fact_n=fact_n*i;
        //cout<<""
        }
        for(int i = 1;i<=r;i++){
        fact_r=fact_r*i;
        }
        for(int i = 1;i<=n-r;i++){
        fact_nr=fact_nr*i;
        }
        ////
        int nCr=fact_n/(fact_r*fact_nr);
    cout<<nCr<<endl;
    
    return 0;
  }