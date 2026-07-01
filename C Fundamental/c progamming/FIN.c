//WAP TO READ THE MARKS OF 5 SUBJECT THROUGH KEYBOARD.FIND OT % ONLY 
#include<stdio.h>
 int main(){
 	  int ph;
 	  printf("ENTER MARKS OF PHYSICS : ");
 	  scanf("%d",&ph);
 	  int math;
 	   printf("ENTER MARKS OF MATH : ");
 	  scanf("%d",&math);
 	  int hindi;
 	   printf("ENTER MARKS OF HINDI : ");
 	   
 	  scanf("%d",&hindi);
 	  
 	  int engli;
 	   printf("ENTER MARKS OF ENGLISH : ");
 	  scanf("%d",&engli);
 	   int chem;
 	    printf("ENTER MARKS OF CHEMISTRY : ");
 	  scanf("%d",&chem);
 	  int total= ph+math+hindi+engli+chem;
 	  float m = total/5;
 	  printf( "THE PERCENTAGE IS :%f  percent ",m);
 	 // printf('%');
 	return 0;
 }
