#include<stdio.h>
 int main(){
 	int m,n; //n == row nad m == column
 	printf("Enter the number of roow : ");
 	scanf("%d",&n);
 	 printf("Enter the number of column : ");
 	 scanf("%d",&m);
 	 for(int i = 1; i<= n ; i++){
 	 	for(int j =1; j<= i; j++){
 	 		printf("%d",j);
 	 		
		  }
		  printf("\n");
	  }
 	return 0;
 }
