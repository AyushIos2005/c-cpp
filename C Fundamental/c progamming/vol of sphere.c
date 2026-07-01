//wap to calc the volume of sphere!!
#include<stdio.h>
#include<math.h>
 int main(){
 	int r;
	  printf("Enter the radius of sphere is:");
	   scanf("%d",&r);
	    float l=3.14;
	   float vol =(4*l*pow(r,3))/3;
	    printf("The volume of sphere is : %.2f",vol);
	    return 0;
 }
