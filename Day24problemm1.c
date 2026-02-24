#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Delete first occurrence of key
struct Node* deleteFirst(struct Node* head, int key) {
    if (head == NULL) return head;

    // If head contains key
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* curr = head;
    while (curr->next != NULL && curr->next->data != key)
        curr = curr->next;

    if (curr->next == NULL) return head; // not found

    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);

    return head;
}

// Create new node
struct Node* newNode(int x) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;
    return n;
}

// Print list
void print(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating list: 10 -> 20 -> 30 -> 20
    struct Node* head = newNode(10);
    head->next = newNode(20);
    head->next->next = newNode(30);
    head->next->next->next = newNode(20);

    printf("Before deletion:\n");
    print(head);

    int key = 20;
    head = deleteFirst(head, key);

    printf("After deleting first %d:\n", key);
    print(head);

    return 0;
}