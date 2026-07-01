#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(){

    char str[100];
    printf("Enter a any statement : ");
    gets(str);

    printf("Your statments : %s",str);

    int a_count = 0;
    int e_count = 0;
    int i_count =0;
    int o_count = 0;
    int u_count =0;

for(int i =0; str[i] != '\0';i++){
        char ch = tolower(str[i]);
        if(ch == 'a') a_count++;
        else if(ch == 'e') e_count++;
        else if(ch == 'i') i_count++;
        else if(ch == 'o') o_count++;
        else if(ch == 'u') u_count++;
    }

    printf("\nIn Your Statment Vowel containing\n");
    printf("A = %d\n",a_count);
    printf("E = %d\n",e_count);
    printf("I = %d\n",i_count);
    printf("O = %d\n",o_count);
    printf("U = %d\n",u_count);

    return 0;
}