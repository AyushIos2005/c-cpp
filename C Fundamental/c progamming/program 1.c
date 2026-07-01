#include<stdio.h>
 int main(){
  int i;
   printf(" the amount is : ");
   scanf("%d",&i);
  int j;
    printf (" the discount is : ");
     scanf("%d",&j); 
     float k = j/100;
     float l = i - k;
      printf(" the groce price : %f",l);
       
     
 return 0;
 }
