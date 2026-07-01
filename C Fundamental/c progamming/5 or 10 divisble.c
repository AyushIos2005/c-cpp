#include<stdio.h>
 int main(){
 	 int num;
 	 printf("\tThe sysment can excuted the number is divisible by 5 or 10 / by both\n");
	  printf("Enter the number : ");
	  scanf("%d",&num);
	  if(num % 5 == 0 && num % 10 == 0)
	   printf("THE %d IS DIVISIBLE BY BOTH 5 AND 10  ", num);
	   if (num %5 == 0 || num % 10 == 0)
	   printf("THE %d IS DIVISIBLE BY  5 OR 10",num);
	     
 	return 0;
 	
 }
