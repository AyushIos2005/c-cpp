// Searching 
#include<stdio.h>
int main(){
    int n;
    printf("Enter a size of Array : ");
    scanf("%d",&n);

    int arr[n];
    printf("\n Enter a Array : ");
    for(int i =0 ; i<n;i++){
        scanf("%d",&arr[i]);
    }

    
    int target;
    printf("Enter a target value : ");
    scanf("%d",&target);

    printf("\n Original Array : ");
    for(int i = 0;i < n;i++){
        printf("%d ",arr[i]);
    }

    // searching ---> Linear search

    int found  =0;
    for(int i =0;i<n;i++){
        if(target == arr[i]){
            printf("\n %d Found at index %d",target,i);
            found =1;
            break;
        }
        
    }
    if(!found){
        printf("\n %d Not found in Array",target);
    }


 return 0;
}