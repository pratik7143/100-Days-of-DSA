#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a circular linked list
void create(int n) {
    int value;
    struct Node *newNode, *temp;

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    // Create first node
    head = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data for node 1: ");
    scanf("%d", &value);
    head->data = value;
    head->next = head; // circular
    temp = head;

    // Create remaining nodes
    for (int i = 2; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);

        newNode->data = value;
        newNode->next = head; // last node points to head
        temp->next = newNode;
        temp = newNode;
    }
}

// Function to traverse circular linked list
void traverse() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("\n");
}

int main() {
    int n;

    printf("How many nodes do you want? ");
    scanf("%d", &n);

    create(n);
    traverse();

    return 0;
}