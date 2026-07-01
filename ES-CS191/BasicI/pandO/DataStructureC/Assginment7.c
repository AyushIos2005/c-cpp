// Application of Single Linked List:
// 7. a) Write a C programs to implement Stack using Single Linked List.
// b) Write a C programs to implement Queue using Single Linked List.

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*link;
};

struct Node* start = NULL;

void push() {
    struct Node *new1;
    new1 = (struct Node *)malloc(sizeof(struct Node));
    if (new1 == NULL) {
        printf("\nOut of Memory Space!\n");
        return;
    }
    printf("\nEnter the data value for the Node: ");
    scanf("%d", &new1->data);

    if (start == NULL) {
        new1->link = NULL;
        start = new1;
    } else {
        new1->link = start;
        start = new1;
    }
}

void pop() {
    struct Node *ptr;
    if (start == NULL) {
        printf("\nList is Empty!\n");
        return;
    }
    ptr = start;
    start = start->link;
    printf("\nThe deleted element is: %d\n",ptr->data);
    free(ptr);
}

void display(){
    struct Node *ptr;
    if (start == NULL) {
        printf("\nList is empty!\n");
        return;
    }
    printf("\nThe List elements are:\n");
    ptr = start;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}


void SLL_Stack(){
    int schoice;
    printf("\nPress 1 for Push element into stack \n");
    printf("\nPress 2 for Pop element from stack\n");
    printf("\nPress 3 for Display stack \n");
    printf("\nPress 4 for exit \n");

    while(1){
        printf("Enter a Choice for stack implment by stack : ");
        scanf("%d",&schoice);

        switch(schoice){

            case 1:  push(); break;
            case 2:  pop(); break;
            case 3: display(); break;
            case 4: return; break;
            default: printf("Try Again !!\n");  
                     
        }
    }

}

void enque(){
    struct Node *new2, *ptr;
    new2 = (struct Node *)malloc(sizeof(struct Node));
    if (new2 == NULL) {
        printf("\nOut of Memory Space!\n");
        return;
    }
    printf("\nEnter the data value for the Node: ");
    scanf("%d", &new2->data);
    new2->link = NULL;

    if (start == NULL) {
        start = new2;
    } else {
        ptr = start;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = new2;
    }
}



void SLL_Queue(){
    int qchoice;
    printf("Press 1 for ENQUE with LinkedList implementation.\n");
    printf("Press 2 for DELQUE with LinkedList implementation.\n");
    printf("Press 3 for Display the Queue.\n");
    printf("Press 4 for Exit.\n");

    while(1){
        printf("\nEnter a choice : ");
        scanf("%d",&qchoice);
        switch (qchoice)
        {

        case 1: enque(); break;
        case 2: pop(); break;
        case 3: display(); break;
        case 4: exit(0); break;
        
        default:
            printf("Error 404 !! Please choose correctly\n");
            break;
        }


    }

}

int main(){
    int choice;
    printf("\n\t\t\tMeun of Application of SLL");
    printf("\n\t\t\t------------------------------------\n");

    printf("Press 1 for LinkedList Stack implemention. \n");
    printf("Press 2 for LinkedList Queue implementation.\n");
    printf("Press 3 for exit.\n");

    while(1){
        printf("Enter a choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            /* code */
            SLL_Stack();
            break;
        case 2:
            SLL_Queue();
            break;    
        case 3:
            exit(0);
            break;
        default:
            printf("Error 404 !! Please Choose propley");
            break;
        }
    }
    return 0;
}