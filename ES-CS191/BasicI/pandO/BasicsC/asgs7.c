// real roots
#include<stdio.h>
#include<math.h>
int main(){
    int a;
    int b;
    int c;

    printf("Enter a Co-efficient of X^2 : ");
    scanf("%d",&a);

    printf("Enter a Co-efficient of X : ");
    scanf("%d",&b);

    printf("Enter a constant term : ");
    scanf("%d",&c);

    /*root of x1 and x2*/

    double x1,x2,D;

    D = ((b*b) -(4*a*c));
    x1=(-b-sqrt(D))/2*a;
    x2=(-b+sqrt(D))/2*a;

    if(D > 0) {
        printf("Two Real Soln are  X1 = %.2lf and X2 = %.2lf",x1,x2);

    }
    else if(D == 0){
        printf("One Real Soln are X1 =%.2lf and X2 = %.2lf",x1,x2);
    }
    else if(D < 0){
        printf("Two Complex Soln are X1=%.2lf and X2 = %.2lf",x1,x2);
    }
    else{
        printf("Not possible!!");
    }

    return 0;

}