#include<iostream>
using namespace std;
class Fraction{
    public:
    int nums;
    int den;

    // Constructor...
    Fraction(int nums, int den){
        this ->nums=nums;
        this->den=den;

    }
    void diplay(){
        cout<<nums<<"/"<<den;
    }
    Fraction operator+(Fraction f){
        int newNums = this-> nums*f.den+f.nums*this->den;
        int newDen =this->den*f.den;
        Fraction ans(newNums,newDen);
        return ans;
    }

};

int main(){
    Fraction f1(1,2);
    Fraction f2(1,3);
    f1.diplay();
    cout<<'+';
    f2.diplay();
    cout<<'=';
   // Fraction f3=f1.add(f2);
    Fraction f3=f1+f2;
    f3.diplay();
}