#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main() {
    struct node *head = NULL, *temp, *newnode;
    int n, value;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);
        newnode->data = value;
        newnode->next = NULL;
        if(head == NULL) {
            head = newnode;  
            temp = newnode;
        } else {
            temp->next = newnode; 
            temp = newnode;       
        }
    }
    printf("\nLinked List: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}

