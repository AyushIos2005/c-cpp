// WAP to calculate si and ci

#include<stdio.h>
#include<math.h>
int main(){
    float p;
    float r;
    float t;

    printf("Enter a Principal amount : ");
    scanf("%f",&p);

    printf("Enter Rate of Interest : ");
    scanf("%f",&r);

    printf("Enter Time : ");
    scanf("%f",&t);

    double si,ci,sia,cia;

    si=(p*r*t)/100;
    sia=si+p;

    cia=p*pow((1+(r/100)),t);
    ci=cia-p;

    printf("Simple Interest:\t%.2lf\n",si);
    printf("Amount:\t%.2lf\n",sia);
    printf("Compund Interest:\t%.2lf\n",ci);
    printf("Amount:\t%.2lf\n",cia);

    return 0;
}