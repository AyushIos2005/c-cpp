// Sorting Ascending Order

#include<stdio.h>
#include<stdlib.h>

// Bubble Sort
void bubblesort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Selection Sort
void selectionsort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int min_index = i;

        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }

        if(min_index != i){
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

// Insertion Sort
void insertionsort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }
}

// Merge Function
void merge(int arr[], int l, int r, int mid){

    int n1 = mid - l + 1;
    int n2 = r - mid;

    int left[n1], right[n2];

    for(int i = 0; i < n1; i++)
        left[i] = arr[l+i];

    for(int j = 0; j < n2; j++)
        right[j] = arr[mid+1+j];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    while(i < n1)
        arr[k++] = left[i++];

    while(j < n2)
        arr[k++] = right[j++];
}

// Merge Sort
void mergesort(int arr[], int l, int r){
    if(l < r){
        int mid = (l+r)/2;

        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);

        merge(arr, l, r, mid);
    }
}

// Display Function
void display(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int size;

    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter elements of array:\n");
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nArray is:\n");
    display(arr, size);

    printf("\nDisplayed Menu\n");

    printf("Press 1 for Bubble Sort\n");
    printf("Press 2 for Selection Sort\n");
    printf("Press 3 for Insertion Sort\n");
    printf("Press 4 for Merge Sort\n");
    printf("Press 5 for Quick Sort\n");
    printf("Press 6 for Exit\n");

    while(1){

        int choice;

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice){

        case 1:
            bubblesort(arr, size);
            printf("Sorted by Bubble Sort\n");
            display(arr, size);
            break;

        case 2:
            selectionsort(arr, size);
            printf("Sorted by Selection Sort\n");
            display(arr, size);
            break;

        case 3:
            insertionsort(arr, size);
            printf("Sorted by Insertion Sort\n");
            display(arr, size);
            break;

        case 4:
            mergesort(arr, 0, size-1);
            printf("Sorted by Merge Sort\n");
            display(arr, size);
            break;

        case 5:
            printf("Quick Sort not implemented yet\n");
            break;

        case 6:
            printf("Thank You for Using Program!!\n");
            exit(0);

        default:
            printf("Invalid Choice!!\n");
        }
    }
}