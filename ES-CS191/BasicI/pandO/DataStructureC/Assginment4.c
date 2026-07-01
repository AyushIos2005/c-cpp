// Assginment 4 circular Quesue....


#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

int cqueue[SIZE];
int front = -1, rear = -1;

void inject(int num) {
    if ((front == 0 && rear == SIZE - 1) || ((rear + 1) % SIZE == front)) {
        printf("Circular Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        cqueue[rear] = num;
        printf("%d is successfully inserted into Circular Queue\n", num);
    }
}

void cdelete() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
    } else {
        int deleted = cqueue[front];
        if (front == rear) {
            front = rear = -1; // Queue has become empty
        } else {
            front = (front + 1) % SIZE;
        }
        printf("%d is deleted from Circular Queue\n", deleted);
    }
}

void display() {
    if (front == -1) {
        printf("Circular Queue is empty\n");
    } else {
        printf("Circular Queue elements are: ");
        int i = front;
        while (1) {
            printf("%d ", cqueue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, num;

    
        printf("\n  Circular Queue \n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");

        while(1){
        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &num);
                inject(num);
                break;
            case 2:
                cdelete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank You for using Circular Queue\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}
