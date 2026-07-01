#include<stdio.h>
 int main(){
 	 int n,i;
 	  printf("ENTER THE LENGTH OF WORD :");
 	  scanf("%d",&n);
 	 int arr[n];
 	 printf("ENTER THE NUMBER:");
 	 for( i=0;i<=n-1;i++){
 	 	scanf("%d",&arr[i]);
 	 	 
 	 	
	  }
	  int sum = 0; 
  	  for(i=0;i<=n-1;i++){
  	  	sum =sum+arr[i];
  	  	//printf("%d",);
	    }
	  printf("THE SUM OF DIGIT IS %d\n",sum);
	  printf("thank you for using");
 	 return 0;
 	
 }
