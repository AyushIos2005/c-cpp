#include<stdio.h>
#include<math.h>
 int main(){
 	printf("\tCompund intrest and Simple intrest Calculater\n");
 	printf("\t**************************************************\n\t=================================================\n");
 	double  p;
 	
 	 printf("Enter the principal amount (in rupess):");
 	 scanf("%lf",&p);
 	 
 	  double r;
 	 printf("Enter the rate of interest per ammumm (in percentage):");
 	 scanf("%lf",&r);
 	 
 	  double t;
 	  printf("Enter the time interval(in year):");
 	  scanf("%lf",&t);
 	  
 	    double si,amt;
 	    double ci;
 	    char b;
           printf("Please entre the s for simple intrest and c for compound intrest  :");
           scanf(" %c",&b);
           
            if(b == 's'){
            	si = (p * r * t ) / 100;
            	printf("The simple intrest is (Rs):%.2lf\n",si);
            	amt = p + si;
            	printf("The amount is(Rs):%.2lf\n",amt);
            	
            	
	  }
	  else if(b == 'c'){
	       	amt = p * pow((1+r/100),t);
		printf("The amount is(Rs.): %.2lf\n",amt);
		ci = amt - p; 
		printf("The compund intrest is (Rs.):%.2lf\n ",ci);      	
	  } else {
	  	int i;
	  	for(i = 1;i <= 5;i++){
	  		printf("please enter correct word may be any trouble.");
		  }
		  printf("/n");
		  printf(" Thank you for visit ");
		  
	  }
	  
 	return 0;
 }
