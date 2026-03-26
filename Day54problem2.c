#include <stdlib.h>
struct Queue {
    struct TreeNode** data;
    int front, rear, size, capacity;
};
struct Queue* createQueue(int capacity) {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = 0;
    q->size = 0;
    q->rear = -1;
    q->data = (struct TreeNode**)malloc(sizeof(struct TreeNode*) * capacity);
    return q;
}
int isEmpty(struct Queue* q) {
    return q->size == 0;
}
void enqueue(struct Queue* q, struct TreeNode* node) {
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = node;
    q->size++;
}
struct TreeNode* dequeue(struct Queue* q) {
    struct TreeNode* node = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return node;
}
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        return NULL;
    }
    struct Queue* q = createQueue(1000);
    int** result = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    enqueue(q, root);
    int level = 0;
    int leftToRight = 1;
    while (!isEmpty(q)) {
        int size = q->size;
        (*returnColumnSizes)[level] = size;
        result[level] = (int*)malloc(sizeof(int) * size);
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = dequeue(q);

            int index = leftToRight ? i : (size - 1 - i);
            result[level][index] = node->val;

            if (node->left) enqueue(q, node->left);
            if (node->right) enqueue(q, node->right);
        }
        leftToRight = !leftToRight;
        level++;
    }
    *returnSize = level;
    return result;
}
