// Basic Calcultor
#include<stdio.h>
#include<stdlib.h>

void i_else(){
    int a;
    int b;
    printf("Enter a number 1: ");
    scanf("%d",&a);
    printf("Enter a Number 2: ");
    scanf("%d",&b);
    char operator;
    printf("Enter a operator(+,-,*,/) : ");
    scanf(" %c",&operator);
    int result;
    if(operator == '+') {
        result = a+b;
        printf("Result : %d",result);
    }
    else if(operator == '-') {
        result = a-b;
        printf("Result : %d",result);
    }
    else if(operator == '*'){
         result=a*b;
        printf("Result : %d",result);
    }
    else if(operator == '/'){
        if(b != 0){
            result = a/b;
            printf("Result : %d",result);
        }
        else{
            printf("Not Possible!!");

        }
    }
    else{
        printf("Invalid Operator!!");
        return;
    }
    

}


void sw(){
    int a;
    int b;
    printf("Enter a number 1: ");
    scanf("%d",&a);
    printf("Enter a Number 2: ");
    scanf("%d",&b);
    char operator;
    printf("Enter a operator(+,-,*,/) : ");
    scanf("%c ",&operator);
    int result;
    switch (operator)
    {
    case '+':
        /* code */
        result = a+b;
        printf("Result : %d",result);
        break;
    case '-':
        result = a-b;
        printf("Result : %d",result);
        break;    
    case '*':
        result = a*b;
        printf("Result : %d",result);
        break;
    case '/':
            if(b != 0){
            result = a/b;
            printf("Result : %d",result);
        }
        else{
            printf("Not Possible!!");

        }
        break;
    default:
    printf("Invalid operator!!");
    return;
        break;
    }
}


int main(){
    
    // it can do by 3 method M-1(if else) and M-2 Switch() and M-3 function for each  i gonna to be saw u both using function 
    int choice;
    printf("Press 1 for gonna with M-1 if esle\n");
    printf("press 2 for  goona with M-2 switch case\n");
    printf("Press 3 for exit\n");

    while(1){
        printf("Enter a Choice : ");
        scanf("%d",&choice);

        if(choice == 1){
            i_else();
        }
        else if(choice == 2){
            sw();
        }
        else if(choice == 3){
            exit(0);

        }
        else{
            printf("Try angain!!");
        }
    }

    return 0;



}