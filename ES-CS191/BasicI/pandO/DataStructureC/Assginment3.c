// Write a meun Driven C Program to implement QUEUE Operation using array:
// 1.Insert an elemnet in the queue:ENQUE(char)
// 2.Delete an element from the queue:char DELQUE()
// 3.Display all element of the queue:DISPLAY()
// 4.Exit the program:EXIT()

#include<stdio.h>
#include<stdlib.h>
#define a 3

char queue[a];
int c=-1;
int rear =-1;
//insert
void enque(){
    char ele;
    if(rear ==  a-1){
        printf("Queue Overflow! Cannot insert more elements...\n");
        return;
    } 
    printf("Enter a character for insert : ");
    scanf(" %c",&ele);
// edge case 
        if(c == -1){
            c =0;
        }
        queue[++rear] = ele;
        printf("'%c' has been inserted .\n",ele);        
}
//deleete
void delque(){
    if(c == -1 || c > rear){
        printf("Queue Underflow! No element to deleted.\n");
        return;
    }
    printf("'%c' is deleted from Queue.\n",queue[c++]);
    if(c >  rear){
        c = rear=-1;//reset factory
    }
}
 //display
 void display(){
    if(c == -1 && rear == -1){
        printf("Queue is empty.\n");
        return;
    }
    printf("Enter element are :\n");
    for(int i= c;i<=rear;i++){
        printf("%c\n",queue[i]);
    }
    
 }

int main(){
    while(1){
     int choose;
     printf("Press 1 for Insert\n");
     printf("Press 2 for Delete\n");
     printf("Press 3 for Display\n");
     printf("Press 4 for Exit\n");
     printf("Press any (1 to 4) : ");
     scanf("%d",&choose);
     switch (choose)
     {
     case 1 :
      enque();

        break;

    case 2:
        delque();
        break;
    case 3:
        display();
        break;
    case 4: 
         exit(0);  
         break;          
     
     default:
     printf("Something is wrong, please try again.\n");
        break;
     } 

    
     }

     return 0;
}