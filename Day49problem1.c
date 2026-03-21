#include <stdio.h>
#include <stdlib.h>
// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }

    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else if (val > root->val) {
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}

// Inorder traversal (Left → Root → Right)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// Free memory (optional but good practice)
void freeTree(struct TreeNode* root) {
    if (root == NULL) return;

    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    struct TreeNode* root = NULL;

    // Example insertions
    int values[] = {5, 3, 7, 2, 4, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        root = insertIntoBST(root, values[i]);
    }

    printf("Inorder Traversal of BST:\n");
    inorder(root);   // Should print sorted order

    freeTree(root);
    return 0;
}
