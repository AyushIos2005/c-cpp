#include<stdio.h>
int main(){
    int a;
    int b;

    printf("Enter a Frist Number : ");
    scanf("%d",&a);
    printf("Enter a Second Number : ");
    scanf("%d",&b);

    if(a > b){
        printf("%d is greater Number",a);
    }
    else{
        printf("%d is greater Number",b);
    }
    return 0;
}