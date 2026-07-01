#include <stdio.h>
#include <string.h>

int main() {
    char first[50];
    char middle[50];
    char last[50];

    printf("Enter your First Name: ");
    fgets(first, sizeof(first), stdin);
    first[strcspn(first, "\n")] = '\0';

    printf("Enter your Middle Name (or press enter if none): ");
    fgets(middle, sizeof(middle), stdin);
    middle[strcspn(middle, "\n")] = '\0'; 

    printf("Enter your Last Name: ");
    fgets(last, sizeof(last), stdin);
    last[strcspn(last, "\n")] = '\0'; 

    printf("Abbreviation of name is: ");
    if (strlen(middle) == 0) {
        // No middle name
        printf("%c. %s\n", first[0], last);
    } else {
        // Middle name present
        printf("%c. %c. %s\n", first[0], middle[0], last);
    }

    return 0;
}
