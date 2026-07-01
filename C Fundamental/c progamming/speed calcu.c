#include<stdio.h>
 int main(){
 	 float dist;
 	printf("Enter the distance in meter of two city:");
 	scanf("%f",&dist);
 	 float time;
 	 printf("Enter the time in second of two city:");
 	scanf("%f",&time);
 	float speed =0;
 	speed = dist/time;
 	 printf("speed is %.2f ms^-1 as per given data is ditance is %.2f m  and time %.2f s",speed,dist,time);
 	 return 0;
 }
