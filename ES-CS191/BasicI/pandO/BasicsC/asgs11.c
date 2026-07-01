#include<stdio.h>
// #include<cbool.h>
int main(){
    int num;

    printf("Enter a number : ");
    scanf("%d",&num);
    if(num < 1){
        printf("Worng input");
    }
    int prime = 0;
    for(int i =2;i < num/2;i++){
        if (i % 2 == 0){
            // printf("%d is not a Prime number",num);
            prime = 1;
            break;
        }
          
    }


    if(prime == 0){
        printf("%d is a prime number",num);
    }
    else{
        printf("%d is not a prime number ",num);
    }
    return 0;

}