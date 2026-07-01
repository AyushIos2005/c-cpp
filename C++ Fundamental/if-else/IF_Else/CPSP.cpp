#include<iostream>
 using namespace std;
   int  main(){
        int cp;
        cout << "Enter the cost price of the product: ";
        cin >> cp;
        int sp;
        cout << "Enter the selling price of the product: ";
        cin >> sp;
        // Calculate profit or loss
         if (sp > cp){// selling price is greater than cost price then profit 
            cout << "profit :  "<<endl<<sp - cp<<endl;
            
         }
          else if (sp < cp){
            cout<<"Loss : "<<endl<< cp - sp << endl;

         }
         else{
            cout<<"Neither profit nor loss"<<endl;
         }
    return 0;
   }