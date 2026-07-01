#include<stdio.h>
#include<stdlib.h>

int arr[100];
int size;

// INSERT
int insert(int arr[], int size){
    int choice, element, pos;

    printf("\n---Insert Menu---\n");
    printf("1. At beginning\n");
    printf("2. At end\n");
    printf("3. At K-th position\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("Enter element: ");
            scanf("%d",&element);

            for(int i = size; i > 0; i--){
                arr[i] = arr[i-1];
            }
            arr[0] = element;
            size++;
            break;

        case 2:
            printf("Enter element: ");
            scanf("%d",&element);

            arr[size] = element;
            size++;
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d",&pos);

            if(pos < 0 || pos > size){
                printf("Invalid position\n");
                return size;
            }

            printf("Enter element: ");
            scanf("%d",&element);

            for(int i = size; i > pos; i--){
                arr[i] = arr[i-1];
            }
            arr[pos] = element;
            size++;
            break;

        default:
            printf("Invalid choice\n");
    }

    return size;
}

// DELETE
int deleteElement(int arr[], int size){
    int choice, pos;

    printf("\n---Delete Menu---\n");
    printf("1. From beginning\n");
    printf("2. From end\n");
    printf("3. From K-th position\n");
    printf("Enter choice: ");
    scanf("%d",&choice);

    if(size == 0){
        printf("Array is empty\n");
        return size;
    }

    switch(choice){
        case 1:
            for(int i = 0; i < size-1; i++){
                arr[i] = arr[i+1];
            }
            size--;
            break;

        case 2:
            size--;
            break;

        case 3:
            printf("Enter position: ");
            scanf("%d",&pos);

            if(pos < 0 || pos >= size){
                printf("Invalid position\n");
                return size;
            }

            for(int i = pos; i < size-1; i++){
                arr[i] = arr[i+1];
            }
            size--;
            break;

        default:
            printf("Invalid choice\n");
    }

    return size;
}

// SEARCH
void search(int arr[], int size){
    int key, found = 0;

    printf("Enter element to search: ");
    scanf("%d",&key);

    for(int i = 0; i < size; i++){
        if(arr[i] == key){
            printf("Element found at index %d\n", i);
            found = 1;
        }
    }

    if(!found){
        printf("Element not found\n");
    }
}

// DISPLAY
void display(int arr[], int size){
    if(size == 0){
        printf("Array is empty\n");
        return;
    }

    printf("Array: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// MAIN
int main(){
    int choice;

    printf("Enter size of array: ");
    scanf("%d",&size);

    printf("Enter elements:\n");
    for(int i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }

    while(1){
        printf("\n---Menu---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                size = insert(arr, size);
                break;

            case 2:
                size = deleteElement(arr, size);
                break;

            case 3:
                search(arr, size);
                break;

            case 4:
                display(arr, size);
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}