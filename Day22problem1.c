#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int countNodes(struct node *head) {
    int count = 0;
    struct node *temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1;

    // Creating linked list
    while (choice) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0/1)? ");
        scanf("%d", &choice);
    }

    printf("\nTotal number of nodes = %d\n", countNodes(head));

    return 0;
}