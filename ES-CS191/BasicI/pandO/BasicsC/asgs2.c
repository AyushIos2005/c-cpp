#include<stdio.h>
int main(){
    int a;
    float b;
    char c;
    double d;

    printf("Enter a integer value : ");
    scanf("%d",&a);

    printf("Enter a float value : ");
    scanf("%f",&b);

    printf("Enter a character value : ");
    scanf(" %c",&c);

    printf("Enter a double value : ");
    scanf("%lf",&d);

    // print the value

    printf("\nInteger value : %d\n It address is : %p\n It size is : %zu bytes\n\n",a,&a,sizeof(a));
    printf("Integer value : %f\n It address is : %p\n It size is : %zu bytes\n\n",b,&b,sizeof(b));
    printf("Integer value : %c\n It address is : %p\n It size is : %zu bytes\n\n",c,&c,sizeof(c));
    printf("Integer value : %lf\n It address is : %p\n It size is : %zu bytes\n\n",d,&d,sizeof(d));

  return 0;
}