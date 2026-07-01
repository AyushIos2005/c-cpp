#include<stdio.h>

int fact(int n){
    if(n == 0 || n == 1) return 1;

    return n*fact(n-1);
}


int main(){
    int n;
    printf("Enter a Nth term : ");
    scanf("%d",&n);

    double sum = 0.0;
    for(int i = 1;i <= n; i++){
        sum += (1.0/fact(i));
    }
    printf("Sum of Nth term is : %lf",sum);

    return 0;
}