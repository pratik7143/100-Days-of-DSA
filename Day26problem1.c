#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* head = NULL;

void insertBeg(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->prev = NULL;
    n->next = head;
    if(head) head->prev = n;
    head = n;
}

void insertEnd(int x) {
    struct Node* n = malloc(sizeof(struct Node));
    n->data = x;
    n->next = NULL;

    if(head == NULL) {
        n->prev = NULL;
        head = n;
        return;
    }
    struct Node* t = head;
    while(t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void traverse() {
    struct Node* t = head;
    while(t) {
        printf("%d ", t->data);
        t = t->next;
    }
}

int main() {
    insertBeg(10);
    insertBeg(20);
    insertEnd(30);

    traverse(); // Output: 20 10 30
}