#include<stdio.h>
 int main(){
 	printf("\tIT IS A POUND OR TONE CALC\n");
	 int kg;
 	printf("ENTER THE NET WEIGHT IN KG :");
 	scanf("%d",&kg);
 	char h;
 	printf("For pounds press'p'/tonne't':");
 	scanf(" %c",&h);
 	if(h=='p'){
 		 float p=2.20*h;
 		printf("%f pound",p);
	 }
	 if(h=='t'){
 		float t=0.001*h;
 		printf("%f tonne",t);
	 }
 	return 0;
 }
