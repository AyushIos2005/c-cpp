// sort an array
#include<stdio.h>
int main(){
    int n;
    printf("Enter a size of array : ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter a array : ");
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("\n Array (original): ");
    for(int i = 0;i<n;i++){
        printf("%d ",arr[i]);
    }

    // bubble sort

    for(int i = n-1;i>=0;i--){//no of pass
        for(int j = 0;j<=i-1;j++){//swapping 
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\n Descending order : ");
    for(int i =0;i<n;i++){
        printf("%d ",arr[i]);
    }

    return 0;

}

