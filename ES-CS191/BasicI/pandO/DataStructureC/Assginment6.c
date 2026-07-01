// Programs using Dynamic Memory Allocation (Linked List):
// 6. Write a Menu Driven C Program to implement the following after creating a Single
// Linked List(SLL)
// a) Insert a node (insert_at_beg / insert_at_end / insert_at_pos) in SLL
// b) Delete a node (del_from_beg / del_from_end / del_at_pos) from SLL
// c) Traverse the nodes of the list.

#include <stdio.h>
#include <stdlib.h>

/*----Function Prototypes-----*/
// void create();
void display();
void insert_begin();
void insert_end();
void insert_pos();
void delete_begin();
void delete_end();
void delete_pos();
/*-----------------------------*/

struct node {
    int data;
    struct node *link;
};

struct node *start = NULL;

int main() {
    int choice;
    
        printf("\n*** SINGLE LINKED LIST OPERATIONS ***\n");
        printf("--------------------------------------\n");
        // insert case 
        printf(" 1. Insert at the beginning\n");
        printf(" 2. Insert at the end\n");
        printf(" 3. Insert at specified position\n");
        printf(" 4. Delete from beginning\n");
        // delete case 
        printf(" 5. Delete from the end\n");
        printf(" 6. Delete from specified position\n");
        printf(" 7. Display\n");
        printf(" 8. Exit\n");
        printf("--------------------------------------\n");
        
        while(1){
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // case 1: create(); break;
       
            case 1: insert_begin(); break;
            case 2: insert_end(); break;
            case 3: insert_pos(); break;
            case 4: delete_begin(); break;
            case 5: delete_end(); break;
            case 6: delete_pos(); break;
            case 7:display();break;

            case 8: exit(0);
            default: printf("\n Wrong Choice!\n"); break;
        }
    }
    return 0;
}

/* Display the list */
void display() {
    struct node *ptr;
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

/* Insert at the beginning */
void insert_begin() {
    struct node *new1;
    new1 = (struct node *)malloc(sizeof(struct node));
    if (new1 == NULL) {
        printf("\nOut of Memory Space!\n");
        return;
    }
    printf("\nEnter the data value for the node: ");
    scanf("%d", &new1->data);

    if (start == NULL) {
        new1->link = NULL;
        start = new1;
    } else {
        new1->link = start;
        start = new1;
    }
}

/* Insert at the end */
void insert_end() {
    struct node *new1, *ptr;
    new1 = (struct node *)malloc(sizeof(struct node));
    if (new1 == NULL) {
        printf("\nOut of Memory Space!\n");
        return;
    }
    printf("\nEnter the data value for the node: ");
    scanf("%d", &new1->data);
    new1->link = NULL;

    if (start == NULL) {
        start = new1;
    } else {
        ptr = start;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = new1;
    }
}

/* Insert at a specified position */
void insert_pos() {
    struct node *ptr, *new1;
    int i, pos;

    new1 = (struct node *)malloc(sizeof(struct node));
    if (new1 == NULL) {
        printf("\nOut of Memory Space!\n");
        return;
    }

    printf("\nEnter the position for the new node: ");
    scanf("%d", &pos);
    printf("Enter the data value of the node: ");
    scanf("%d", &new1->data);
    new1->link = NULL;

    if (pos == 1) {
        new1->link = start;
        start = new1;
    } else {
        ptr = start;
        for (i = 1; i < pos - 1 && ptr != NULL; i++) {
            ptr = ptr->link;
        }
        if (ptr == NULL) {
            printf("\nPosition not found!\n");
            free(new1);
            return;
        }
        new1->link = ptr->link;
        ptr->link = new1;
    }
}


/* Delete from beginning */
void delete_begin() {
    struct node *ptr;
    if (start == NULL) {
        printf("\nList is Empty!\n");
        return;
    }
    ptr = start;
    start = start->link;
    printf("\nThe deleted element is: %d\n", ptr->data);
    free(ptr);
}

/* Delete from end */
void delete_end() {
    struct node *ptr, *temp;
    if (start == NULL) {
        printf("\nList is Empty!\n");
        return;
    }
    if (start->link == NULL) {
        // Only one node
        printf("\nThe deleted element is: %d\n", start->data);
        free(start);
        start = NULL;
    } else {
        ptr = start;
        while (ptr->link != NULL) {
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = NULL;
        printf("\nThe deleted element is: %d\n", ptr->data);
        free(ptr);
    }
}

/* Delete from specified position */
void delete_pos() {
    int i, pos;
    struct node *ptr, *temp;

    if (start == NULL) {
        printf("\nThe List is Empty!\n");
        return;
    }

    printf("\nEnter the position of the node to be deleted:\t");
    scanf("%d", &pos);

    if (pos == 1) {
        ptr = start;
        start = start->link;
        printf("\nThe deleted element is: %d\n", ptr->data);
        free(ptr);
        return;
    }

    ptr = start;
    for (i = 1; i < pos && ptr != NULL; i++) {
        temp = ptr;
        ptr = ptr->link;
    }

    if (ptr == NULL) {
        printf("\nPosition not Found!\n");
        return;
    }

    temp->link = ptr->link;
    printf("\nThe deleted element is: %d\n", ptr->data);
    free(ptr);
}
