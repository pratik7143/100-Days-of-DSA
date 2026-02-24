struct ListNode* removeElements(struct ListNode* head, int val) {
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
    if (head == NULL) return head;
    struct ListNode* curr = head;
    while (curr->next != NULL) {
        if (curr->next->val == val) {
            struct ListNode* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
        } 
        else 
        {
            curr = curr->next;
        }
    }
    return head;
}
