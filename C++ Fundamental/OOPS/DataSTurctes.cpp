#include<iostream>
#include<vector>
using namespace std;
class Vector{
    public:
    int size;
    int capacity;
    int *arr;
    Vector(){
        size=0;
        capacity=1; 
        arr=new int[1];
    }
    void add(int ele){
        if(size==capacity){
          capacity *=2;
          int *arr2=new int[capacity];
          for(int i=0;i<size;i++){
            arr2[i]=arr[i];
          }
        }
        arr[size++]=ele;
        // size++;


    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    } 
    int get(int idx){
        if(size == 0){
            cout<<"Arry is Empty"<<endl;
        }
        if(idx>= size) cout<<"Invalid Index";
        return arr[idx];
    }
    void remove(){
        if(size == 0){
            cout<<"Array is Empty"<<endl;
        }
        size--;
    }


};
//  using namespace std;
 int main(){
    Vector v;
    v.add(10);
    v.print();
     v.add(23);
    v.print();
     v.add(20);
    v.print();
     v.add(05);
    v.print();
    // cout<<v.get(10)<<endl;
    v.remove();
 }