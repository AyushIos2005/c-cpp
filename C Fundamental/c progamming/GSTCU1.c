 // THE MINI PROJECT GOOD TAX (GST) CALCU
#include<stdio.h>
 int main(){
          float cp;
          printf("ENTER THE COST OF PRODUCTION : RS. ");
          scanf("%f",&cp);
           float cgst,sgst;
           printf("ENTER THE TAX % IMPOSED BY CENTRAL,i.e., CGST: ");
           scanf("%f",&cgst);
           printf("ENTER THE TAX % IMPOSED BY CENTRAL,i.e., SGST: ");
           scanf("%f",&sgst);
             float total = 0;
              float amt_cgst = ((cgst/100)*cp);
              float amt_sgst = ((sgst/100)*cp);
              total =  cp+amt_cgst +amt_sgst;
              
	  printf("THE CENTERAL AND STATE TAX IS (CGST) IS %.1f'%'AND (SGST) IS %.1f'%'",cgst,sgst);
	  printf("\n THE GROSS TAX(GST) IS %.2f",total);
 	
 	 return 0;
 	 
 }
