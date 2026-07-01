// Write a program to create a structure with the object name,roll no and marks(int).From this create a student a DB. Display the name of all the student having the highest marks. USe dynamic memory allocation for  better memory utilization.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct SDB
{
    char name[15];
    int roll;
    int marks;
};

int main(){
    int n;
    printf("Enter a number of Student : ");
    scanf("%d",&n);

    struct SDB *students = (struct SDB *)malloc(n * sizeof(struct SDB));
    if (students == NULL) {
        printf("Memory Error!!!\n");
        return -1;
    }

    for(int i =0;i<n;i++){
        printf("\nEnter details of student %d:\n", i + 1);

        printf("Enter a student name  : ");
        // gets(students[i].name);
         scanf(" %[^\n]", students[i].name);

        printf("Enter a Roll No : ");
        scanf("%d",&students[i].roll);

        printf("Enter Marks : ");
        scanf("%d",&students[i].marks);

    }


    int highest = students[0].marks;
    for (int i = 1; i < n; i++) {
        if (students[i].marks > highest) {
            highest = students[i].marks;
        }
    }

    printf("\nStudent(s) with highest marks (%d):\n", highest);
    for (int i = 0; i < n; i++) {
        if (students[i].marks == highest) {
            printf("Name: %s, Roll No: %d\n", students[i].name, students[i].roll);
        }
    }

    free(students);


    return 0;
}