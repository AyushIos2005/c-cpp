// i=n
// ∑ x^X  
// x = i

#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("Enter a Nth term : ");
    scanf("%d",&n);
    int sum = 0;
    for(int i = 1 ; i <= n; i++){
        sum += pow(i,i);
        // printf("Sum : %d\n",sum);
    }

    printf("Sum : %d\n",sum);


    return 0;
}