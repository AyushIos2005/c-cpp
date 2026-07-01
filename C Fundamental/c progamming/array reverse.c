#include<stdio.h>
 int main(){
 	int n;
 	 printf("enter the size of array:");
 	 scanf("%d",&n);
 	 
 	char arr[n],brr[n];
 	  printf("enter the name : ");
 	  int i;
 	  for(i = 0;i<n;i++){
 	  	scanf("%c",&arr[i]);
 	  	
 	  	
	   }
	   for(i = 0;i<n;i++){
 	         brr[i]=arr[n- 1 -i];
 	         
 }
  	         for(i = 0;i<n ;i++){
 	  	printf("%c",brr[i]);
 	  }
	  
 	return 0;
 }
