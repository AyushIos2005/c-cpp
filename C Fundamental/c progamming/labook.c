#include<stdio.h>
 int main(){
     	  int n, b;
     	  printf("Enter the number of rows:");
     	  scanf("%d",&n);
     	  printf("Enter the number columns :");
     	  scanf("%d",&b);
     	  char prit;
     	   printf("Press the character :");
     	   scanf(" %c",&prit);
     	  for(int i = 1;i<=n; i++){
     	  	for(int j =1;j<=b;j++){
     	  		printf("%c",prit);
		       }
		       printf("\n");
	       }
     	  
	
 	return 0;
 	
 }
