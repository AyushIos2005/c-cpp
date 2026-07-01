#include<stdio.h>
#include<string.h>
 int main(){
 	 printf("\t DISCALMER!");
 	 printf("FOR METER PRESS 'm'\n FOR CM PRESS 'x'\n FOR MILES PRESS 'i'\n");
 	int km;
 	 printf("ENTER THE DISTANCE BETWEEN TO CITY :");
 	 scanf("%d",&km);
 	   
// 	   1 km = 1000m
// 	   1km=100000cm
// 	   1km=0.6213 mile
	   printf("Example: km to meter ,km to mile..");
	   char c;   
 	   printf("What the type you wann be:");
 	   scanf(" %c",&c);
 	    if (c == 'm'){
 	    	int m=km*1000;
 	    	printf("The distance between two city in meter is :%d meter ",m);
 	    	
	     }
 	   else if (c == 'x'){
 	   	 int x=km*100000;
 	   	printf("The distance between two city in centimeter is %d centimeter",x);
 	   	
	    }
	    else if(c == 'i'){
	    	float i=km*0.6213;
	    	printf("The distance between two city in miles is %f miles",i);
	    }
	    else{
	    	printf("Enter the correct input");
	    }
	    
 	   

 	return 0;
 }
