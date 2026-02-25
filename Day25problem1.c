#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* createNode(int x) {
    struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->val = x;
    temp->next = NULL;
    return temp;
}

int countOccurrences(struct ListNode* head, int key) {
    int count = 0;
    while (head != NULL) {
        if (head->val == key)
            count++;
        head = head->next;
    }
    return count;
}

int main() {
    struct ListNode *head = NULL, *temp;
    
    // Creating sample list: 1 -> 2 -> 3 -> 2 -> 4
    head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(2);
    head->next->next->next->next = createNode(4);

    int key = 2;
    printf("Occurrences of %d = %d", key, countOccurrences(head, key));
    
    return 0;

}
