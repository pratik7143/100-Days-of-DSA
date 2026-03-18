#include <stdlib.h>
/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct Queue {
    struct TreeNode** arr;
    int front, rear, size;
};
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->arr = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
    q->front = 0;
    q->rear = 0;
    q->size = 0;
    return q;
}
void enqueue(struct Queue* q, struct TreeNode* node)
{
    q->arr[q->rear++] = node;
    q->size++;
}
struct TreeNode* dequeue(struct Queue* q) {
    q->size--;
    return q->arr[q->front++];
}
int isEmpty(struct Queue* q) {
    return q->size == 0;
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    int capacity = 2000;  // safe size for constraints
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnColumnSizes = (int*)malloc(sizeof(int) * capacity);
    struct Queue* q = createQueue(capacity);
    enqueue(q, root);
    int levelCount = 0;
    while (!isEmpty(q)) {
        int size = q->size;

        result[levelCount] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[levelCount] = size;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(q);
            result[levelCount][i] = node->val;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }

        levelCount++;
    }
    *returnSize = levelCount;
    return result;
}
