#include<stdio.h>
#include<math.h>
 int main(){
 	 printf("CALCUTATION OF AX^2+BX+C=0 \n");
 	  int a;
 	   printf("Enter the coffecient of x^2:");
 	   scanf("%d",&a);
 	   int b;
 	   printf("Enter the coeffecient of x:");
 	   scanf("%d",&b);
 	   int c;
 	    printf("Enter the constant :");
 	    scanf("%d",&c);
      	     double d;
      	     d =sqrt(b*b -4*a*c);
	     printf("The discriminant of quadratic equation : %.2lf\n",d);
      	     double x1;
	     x1 = (-b-d)/(2*a);
	     double x2;
	     x2 =(-b+d)/(2*a);
	           	     
      	     if(d>0){
      	     	 printf("The root are real and distinct.\n");
      	     	 printf("X = %.2lf,X = %.2lf",x1,x2);
      	     	 
      	     	 
     	     	  }
     	     else if(d==0){
     	     	 printf("The root are real and equal.\n");
      	     	 printf("X = %.2lf,X = %.2lf",x1,x2);
     	     	
		}	  
      	     else if(d<0){
      	     	
	           printf("The root are complex with non zero imagarir.\n");
      	     	 printf("X = %.2lf,X = %.2lf",x1,x2);
		 }
 	return 0;
 }
