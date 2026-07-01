#include<stdio.h>
 int main(){
 	 int m,n;//m--> col and n--> row 
 	printf("Enter the number of row :");
 	scanf("%d",&n);
 	printf("Enter the number of column :");
 	scanf("%d",&m);
 	
 	 for(int i =1;i<= n;i++){//no.of line
 	 	for(int j =1;j<=i;j++){//no of start in each line
 	 		printf(" ");
 	 	}
 	 		for(int k= 1;k<= n+1-i;k++){
 	 			printf("*");
			  }
 	 		
		  
		  printf("\n");
	  }
 	return 0;
 }
