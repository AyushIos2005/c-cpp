#include<stdio.h>

int main() {
    char name[50];
    int id;
    float basic_salary, allowances, deductions, net_salary;

    printf("Enter Employee Name: ");
    fgets(name, sizeof(name), stdin);

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    printf("Enter Basic Salary: ");
    scanf("%f", &basic_salary);

    printf("Enter Allowances: ");
    scanf("%f", &allowances);

    printf("Enter Deductions: ");
    scanf("%f", &deductions);

    net_salary = basic_salary + allowances - deductions;

    printf("\n---------------- Salary Slip ----------------\n");
    printf("Employee Name : %s", name);
    printf("Employee ID   : %d\n", id);
    printf("Basic Salary  : %.2f\n", basic_salary);
    printf("Allowances    : %.2f\n", allowances);
    printf("Deductions   : %.2f\n", deductions);
    printf("---------------------------------------------\n");
    printf("Net Salary   : %.2f\n", net_salary);
    printf("---------------------------------------------\n");

    return 0;
}

