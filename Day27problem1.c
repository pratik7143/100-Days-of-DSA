#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int getIntersectionNode(struct Node* head1, struct Node* head2) {
    if (head1 == NULL || head2 == NULL)
        return -1;
    struct Node *a = head1;
    struct Node *b = head2;
    while (a != b) {
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }
    return (a != NULL) ? a->data : -1;
}

int main() {
    struct Node* head1 = createNode(10);
    head1->next = createNode(20);
    head1->next->next = createNode(30);
    struct Node* head2 = createNode(15);
    head2->next = createNode(25);
    struct Node* intersect = createNode(40);
    intersect->next = createNode(50);
    head1->next->next->next = intersect;  
    head2->next->next = intersect;      
    int result = getIntersectionNode(head1, head2);

    if (result != -1)
        printf("Intersection point data = %d\n", result);
    else
        printf("No intersection\n");

    return 0;
}