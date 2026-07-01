// WAP to print your name and your roll no in two line.

#include<stdio.h>
#include<string.h>
int main(){

   char str[50]; //for string store the name 
   int rollno;  //for store the rollno 

    printf("Enter Your Name : ");
//    scanf("%s",&str);//one way 
    gets(str); // second method 

    printf("Enter Your Roll No : ");
    scanf("%d",&rollno);
    
//  for print output in two line
    printf("Your Name : %s\n",str);
    printf("Roll no : %d\n",rollno);

    return 0;
}