#include<stdio.h>
#include<string.h>
 int main(){
 	printf("\t::Disclamer::\n");
 	printf("\tCORRECT : Shanti WHILE INCORRCET : SHANTI,shanti...\n");
 	char ch[20];
 	 printf("Enter the name :");
 	 scanf("%s", ch);
 	  if(strcmp(ch,"Ganesh") == 0){
 	  	printf("\tWELCOME TO THIS WORLD\n ");
 	  	printf("Dear Ganesh & Deepika\n");
 	  	printf("May your journey together be filled with love, laughter, and endless joy. As you start this beautiful chapter,\n may every moment be as special as your love for each other. Wishing you a lifetime of happiness,\n togetherness, and unforgettable memories! ");
 	  	printf("\nCongratulations for your wedding!\n ");
	   }
 	  else {
 	  	int n,m;
 	  	printf("Enter the number of  row : ");
 	  	scanf("%d",&n);
 	  	printf("Enter the number of column : ");
 	  	scanf("%d",&m);
 	  	char boby;
 	  	printf("Enter any character : ");
 	  	scanf(" %c",&boby);
 	  	//scanf("%d",&m);
 	  	 for(int i = 1; i<= n; i++){
 	  	 	for(int j = 1; j <= i; j++){
 	  	 		printf("%c",boby);
 	  	 		
			    }
 	  	 	printf("\n");
		    }
	   }
	   printf("THANK YOU FOR YOUR TIME !!");
  return 0;
 }
