// Basic calculator 
#include<stdio.h>
#include<math.h>
 int main(){
 	int num1;
 	 
 	 printf("Enter first number :");
 	 scanf("%d",&num1);
 	int num2;
 	 
 	 printf("Enter second number :");
 	 scanf("%d",&num2);
 	 int res;
	 char op;
	 printf("Enter the operater(+,-,*,/):");
	 scanf(" %c",&op);
	 switch(op)
	 {
	 	case '+':
	 		res = num1 + num2;
	 		printf("Desire value is %d",res);
	 		break;
	 	case '-':
		         res = num1 - num2;
		         printf("Desire value is %d",res);
		         break;
		case '*':
		         res = num1 * num2;
		         printf("Desire value is %d",res);
		         break;
		case '/':
		         if(num2 != 0){
		         	res = num1/num2;
		         	printf("Desire value is %d",res);
		         } else{
		         	printf("Division is not possible!!");
		         } 
		         break; 
		               	
	 	default :
		        printf("Getting something wrong with you\n");	
	 		
	 		
	 }
	 
 	return 0;
 } 
