#include<bits/stdc++.h>
using namespace std;

class Temp{
    string itemID,itemName,search;
    fstream file,file1;
    int itemQty,itemPrice;
    int totalAmount,quantity,itemRate;
    char _choice;
   public:
    void addProduct(void);
    void viewProduct(void);
    void buyProduct(void);
}obj;


int main(){
    cout<<"Welcome to Binod Store"<<endl;
    cout<<"Your Trusted Store Partner"<<endl;
    char choice;
    

    cout<<"Press 1 start shopping "<<endl;
    cout<<"Press 2 to Exit"<<endl;
    cout<<"Enter your choice : ";

    cin>>choice;
     switch(choice){
        case 'A' :
        // admin selection
         obj.addProduct();
            break;

        case '1':
        // user selection 
        obj.viewProduct();
        obj.buyProduct();
            // cout<<"Happy Shopping !"<<endl;
            break;
        case '2':
            cout<<"Thank you for visiting Binod Store !"<<endl;
            exit(0);
            break;
        default:
            cout<<"Invalid Choice !"<<endl;
            break;
     }

    return 0;
}

void Temp :: addProduct(){
    
    cout<<"Enter Item ID : ";
    cin>>itemID;
    cout<<"Enter Item Name : ";
    cin>>itemName;
    cout<<"Enter Item Quantity : ";
    cin>>itemQty;
    cout<<"Enter Item Price : ";
    cin>>itemPrice;
    cout<<"Product Added Successfully !"<<endl;
    cout<<"A wait for selter to confirm your product "<<endl;
    
    file.open("Data.txt",ios :: out | ios :: app);
    file<<itemID<<"\t"<<itemName<<"\t"<<itemQty<<"\t"<<itemPrice<<endl;
    file.close();
}
void Temp :: viewProduct(){
    
    file.open("Data.txt",ios :: in);
         file>>itemID>>itemName>>itemQty>>itemPrice;
        while(!file.eof()){
        // cout<<itemID<<"\t"<<itemName<<"\t"<<itemQty<<"\t"<<itemPrice<<endl;
            cout<<"--------------------------------"<<endl;
            cout<<"Item ID : "<<itemID<<endl;
            cout<<"Item Name : "<<itemName<<endl;
            cout<<"Item Quantity : "<<itemQty<<endl;

            cout<<"Item Price : "<<itemPrice<<endl;
            
            cout<<"--------------------------------"<<endl;       
            file>>itemID>>itemName>>itemQty>>itemPrice;
        }

    file.close();
}
void Temp :: buyProduct(){

    _choice = 'y';
    while(_choice == 'y' || _choice == 'Y'){

    

   file.open("Data.txt",ios::in);
   file1.open("Temp.txt",ios::out|ios::app);

   file>>itemID>>itemName>>itemQty>>itemPrice;

   cout<<"Enter Product ID : ";
   cin>>search;

   cout<<"Enter Quantity : ";
   cin>>quantity;

   while(!file.eof()){
        if(itemID == search){
            itemQty = itemQty - quantity;
            file1<<itemID<<"\t"<<itemName<<"\t"<<itemQty<<"\t"<<itemPrice<<endl;
            itemRate = itemPrice * quantity;
            totalAmount = totalAmount + itemRate;
            cout<<"Item Bought Successfully !"<<endl;
            cout<<"------------PAYMENT BILL--------------------"<<endl;
            cout<<"Your Total Amount is : "<<totalAmount<<endl;
            cout<<"-------------------------------------------"<<endl;


        
        }else{
            file1<<itemID<<"\t"<<itemName<<"\t"<<itemQty<<"\t"<<itemPrice<<endl;
        }
        file>>itemID>>itemName>>itemQty>>itemPrice;
   }
   
   file.close();
   file1.close();
   remove("Data.txt");
   rename("Temp.txt","Data.txt");
    
    cout<<"\n Continue Shopping ?\n(YES/NO)";
    cin>>_choice;
    }
}



