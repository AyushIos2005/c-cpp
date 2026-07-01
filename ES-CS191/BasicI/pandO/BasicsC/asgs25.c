// WAP to create a file name "Profile.txt" write Your detils in that file and copy the content of that file into another file"myProfile.txt"
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp1, *fp2;
    char ch;

    fp1 = fopen("Profile.txt", "w");
    if (fp1 == NULL) {
        printf("Unable to create file.\n");
        return 1;
    }

    char name[50], age[5], course[50];
    printf("Enter your name: ");
    scanf(" %[^\n]", name);
    printf("Enter your age: ");
    scanf(" %[^\n]", age);
    printf("Enter your course: ");
    scanf(" %[^\n]", course);

    
    fprintf(fp1, "Name: %s\n", name);
    fprintf(fp1, "Age: %s\n", age);
    fprintf(fp1, "Course: %s\n", course);
    fclose(fp1);

    
    fp1 = fopen("Profile.txt", "r");
    if (fp1 == NULL) {
        printf("Unable to open file for reading.\n");
        return 1;
    }

    
    fp2 = fopen("myProfile.txt", "w");
    if (fp2 == NULL) {
        printf("Unable to create myProfile.txt\n");
        fclose(fp1);
        return 1;
    }

    
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }

    printf("\nContent copied to myProfile.txt successfully.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}
