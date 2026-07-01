//normal method.c ncr=n/r(n-r)
#include<iostream>
 using namespace std;
 int comb(int a){
    int b = 1;
        for(int i =1 ;i<=a;i++){
            b=b*i;
        }
        return ṇ;
 }
  int main(){
    int n;
    cout<<"Enter any number n : ";
    cin>>n;
     int r;
    cout<<"Enter any number r : ";
    cin>>r;
    //cout<<n<<"! = ";
    int fact_n=comb(n);
    int fact_r=comb(r);
    int fact_nr=comb(n-r);
    
        ////
        int nCr=fact_n/(fact_r*fact_nr);
    cout<<nCr<<endl;
    
    return 0;
  }