#include<stdio.h>
#include<stdlib.h>
int iteration;
void binarysearch(int arr[],int n,int target){
    int left = 0;
    int right = n - 1;
    iteration = 0;

    while(left <= right){
        int mid = left + (right - left) / 2;
        iteration++;

        if(arr[mid] == target){
            printf("Element found at index %d\n",mid);
            printf("Number of iterations: %d\n", iteration);
            return;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    printf("Element not found in the array\n");
    return;
}

int interpolationsearch(int arr[],int n,int target){
    int left = 0;
    int right = n - 1;
    iteration = 0;

    while(left <= right){
        int mid = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        iteration++;

        if(arr[mid] == target){
            // printf("Element found at index %d\n",mid);
            // printf("Number of iterations: %d\n", iteration);
            return mid;
        }
        else if(arr[mid] < target){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    // printf("Element not found in the array\n");
    return -1;
}

int main(){
    printf("Press 1 for Binary Search\n");
     printf("Press 2 for Interpolation Search\n");
     printf("Press 3 for Exit\n");
     int choice,target;
     int n,b;
     printf("Enter a size of array : ");
        scanf("%d",&n);
        int arr[n];
        printf("Enter a element of array : ");
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }

     while(1){
          printf("Enter a choice : ");
          scanf("%d",&choice);

            switch(choice){
                 case 1:
                        printf("Enter a target element : ");
                        scanf("%d",&target);
                        binarysearch(arr,n,target);
                        break;
                 case 2:
                        printf("Enter a target element : ");
                        scanf("%d",&target);
                        b=interpolationsearch(arr,n,target);
                        if(b!=-1){
                            printf("Element found at index %d\n",b);
                            printf("Number of iterations: %d\n", iteration);
                        }
                        else{
                            printf("Element not found in the array\n");
                        }
                        break;
                 case 3:
                        exit(0);
                 default:
                        printf("Invalid choice!!\n");
            }
     }
}