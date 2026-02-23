#include <stdio.h>
#include <stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* createNode(int val) {
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = val;
    newnode->next = NULL;
    return newnode;
}

// Insert at end
void insertEnd(struct ListNode** head, int val) {
    struct ListNode* newnode = createNode(val);

    if (*head == NULL) {
        *head = newnode;
        return;
    }

    struct ListNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
}

// Merge two sorted lists
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // Attach remaining part
    tail->next = (list1 != NULL) ? list1 : list2;

    return dummy.next;
}

// Print list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct ListNode* list1 = NULL;
    struct ListNode* list2 = NULL;

    int n1, n2, val;

    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);
    printf("Enter elements (sorted): ");
    for (int i = 0; i < n1; i++) {
        scanf("%d", &val);
        insertEnd(&list1, val);
    }

    printf("Enter number of elements in List 2: ");
    scanf("%d", &n2);
    printf("Enter elements (sorted): ");
    for (int i = 0; i < n2; i++) {
        scanf("%d", &val);
        insertEnd(&list2, val);
    }

    printf("\nList 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct ListNode* merged = mergeTwoLists(list1, list2);

    printf("\nMerged List: ");
    printList(merged);

    return 0;

}
