#include<stdio.h>
 int main(){
    int n[5];
    printf("Enter a number : ");
    for(int i=0;i<5;i++)
        scanf("%d",&n[i]);
    
    //for reverse....
    for(int i=4;i>=0;i--)
        printf("%d ",n[i]);
    
    return 0;
 }