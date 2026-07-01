#include<stdio.h>
#include<stdlib.h>
# define size 3
int top = -1;
int stack[size];

void push(){
    int ele;
    if(top == size-1){
        printf("Error!!Stack is full!!\n");
    }  
    // int ele;
   else{ 
    printf("Enter the element to be pushed: ");
    scanf("%d",&ele);
    stack[++top]=ele;
    printf("Element %d pushed Successfully!\n",ele);
   }
}
int pop(){
    if(top == -1){
        printf("Error!! Stack is empty\n");
        return -1;
    }
    printf("Element %d is popped!!\n",stack[top]);
    top--;
    return top;
}
void display(){
    if(top == -1){
        printf("Stack is empty\n");
    }
    for(int i=size-1;i>=0;i--){
        printf(" \t\n%d\n ",stack[i]);
        
    }
    printf("Top element : %d\n",stack[top]);
}

int main(){
     printf("Press 1 for Insert in Stack\n");
    printf("Press 2 delete from stack\n");
    printf("Press 3 for display\n");
    printf("Press 4 for exit\n");
    while(1){
    int choose;

    printf("Enter any (1 to 4) : ");
    scanf("%d",&choose);
    switch (choose)
    {
    case 1:
         push();
        break;
    case 2:
        pop();
        break;
    case 3:
          display();
          break;
    case 4:
            exit(0);
           break;       
    
    default:
      printf("Something is fault");
        break;
    }
}
return 0;
}