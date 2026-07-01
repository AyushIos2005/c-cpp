// swapping through function

#include<stdio.h>


void swap1(int *a,int *b){

    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;   

}

int main(){
    int a,b;
    printf("Enter a 1st Number : ");
    scanf("%d",&a);

    printf("Enter a 2nd Number : ");
    scanf("%d",&b);

     swap1(&a,&b);
    
    printf("1st Number:  %d and 2nd Number:   %d",a,b);



}