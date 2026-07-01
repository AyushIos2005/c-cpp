#include<stdio.h>
 int main(){
 	int m,n;
 	printf("Enter the no of rows : ");
 	scanf("%d",&n);
 	 printf("Enter the no of column :");
 	 scanf("%d",&m);
 	  for(int i = 1;i<= n; i++){
 	  	int a =1;
 	  	for(int j= 1; j<= m; j++){
 	  		int d = a +64;
 	  		char ch =(char)d;
 	  		printf(" %c ",ch);
 	  		a++;
		   }
		   printf("\n");
	   }
 	return 0;
 }
