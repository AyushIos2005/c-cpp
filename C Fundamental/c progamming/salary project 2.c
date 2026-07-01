#include <stdio.h>

int main() {
    float sale;
    float basic;
    float hra;
    float da;
    float incentive;
    float bonus;
    float conv;

    printf("Enter the total sales of month: ");
    scanf("%f", &sale);

    if (sale >= 100000) {
        basic = 4000;
        hra = 20 * basic / 100;
        da = 110 * basic / 100;
        incentive = sale * 10 / 100;
        bonus = 1000;
        conv = 500;
    } else {
        basic = 4000;
        hra = 10 * basic / 100;
        da = 110 * basic / 100;
        incentive = sale * 4 / 100;
        bonus = 500;
        conv = 500;
    }

    float salary = 0; // Change to float
    salary = basic + hra + da + incentive + bonus + conv;

    printf("\t====================\n");
    printf("SALARY RECEIPT OF EMPLOYEE.\n");
    printf("Total sale = %f\n", sale);
    printf("Basic = %f\n", basic);
    printf("HRA = %f\n", hra);
    printf("DA = %f\n", da);
    printf("Incentive = %f\n", incentive);
    printf("Bonus = %f\n", bonus);
    printf("Conveyance = %f\n", conv);
    printf("GROSS SALARY = Rs.%f\n", salary);

    return 0;
}
