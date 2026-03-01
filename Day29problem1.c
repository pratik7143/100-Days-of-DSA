#include <stdlib.h> 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy; 
    dummy.next = NULL;
    struct ListNode* curr = &dummy;
    
    int carry = 0;
    
    // Loop continues as long as there are digits left in l1 or l2, 
    // OR if there is a leftover carry that needs to be added as a new node.
    while (l1 != NULL || l2 != NULL || carry != 0) {
        int sum = carry;
        
        // Add l1's value if it's available
        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        // Add l2's value if it's available
        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }
        
        // Calculate the new carry for the next decimal place (could be 1 or 0)
        carry = sum / 10;
        
        // Allocate a new node for the resulted digit
        struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
        newNode->val = sum % 10; // Get the digit to store (0-9)
        newNode->next = NULL;
        
        // Append it to our result list and move the 'curr' pointer forward
        curr->next = newNode;
        curr = curr->next;
    }
    
    // The head of the resulting numeric list is the node after the dummy
    return dummy.next;
}
