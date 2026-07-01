// Swap without 3rd variable
#include<stdio.h>
int main(){
    int a;
    int b;
    
    printf("Enter a First Number(a) : ");
    scanf("%d",&a);

    printf("Enter a Second Number(b) : ");
    scanf("%d",&b);

    printf("Before swapping\n");
    printf("First Number(a) : %d\nSecond Number(b) : %d\n",a,b);

    a=a+b;
    b=a-b;
    a=a-b;

    printf("\nAfter swapping\n");
    printf("Fist Number(a) : %d\nSecond Number(b) : %d\n",a,b);
    return 0;
}
