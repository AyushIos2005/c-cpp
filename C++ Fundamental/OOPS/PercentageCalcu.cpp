//  Percentage Calcutor
#include<iostream>
#include<string>
using namespace std;
class SudentMarks{
    public:
    string name;
    int phmark;
    int matmarks;
    int chemarks;
    int hmarks;
    int engmarks;
    int totalmarks;
    float percentage;
   
    void vermaline(){
        cout<<"\n-------------------------------------------------------------------------------\n";
        
    }
   
    /*Constructor*/
    // SudentMarks(string n,int p,int m,int c,int h,int en){
    //     name:n;

    //     phmark:p;
    //     matmarks:m;
    //     chemarks:c;
    //     hmarks:h;
    //     engmarks:en;
    // }
    void percent(int sum){
            vermaline();
                percentage=(sum/5.0);
                cout<<"Percentge is :"<<percentage<<"%";
                vermaline();
                
    }
    
    
    
    int total(int marks1,int marks2,int marks3, int marks4,int marks5){
            int sum=0;
            sum=sum+marks1+marks2+marks3+marks4+marks5;
            totalmarks=sum;
            cout<<"Total Marks: "<<totalmarks<<endl;
            percent(totalmarks);
            vermaline();
     }
   
    void datasup(int i){
     cout<<"\nEnter a detail of student "<<i+1<<":-\n";
     vermaline();
    cout<<"Name of student :";
     cin.ignore();
    getline(cin,name);
    cout<<"Hindi(Marks): ";
    cin>>hmarks;
    cout<<"English(Marks): ";
    cin>>engmarks;
    cout<<"Physics(Marks): ";
    cin>>phmark;
    cout<<"Chemsitry(Marks): ";
    cin>>chemarks;
    cout<<"Maths(Marks): ";
    cin>>matmarks;
    
      total(hmarks,engmarks,phmark,chemarks,matmarks);

    
   }
      
   


};
int main(){
  int n;
    cout<<"Enter a number of students: ";
    cin>>n;

    SudentMarks arr[n];
    for(int i=0;i<n;i++){
        // vermaline();
        arr[i].datasup(i);
    }
}