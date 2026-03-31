#include <stdlib.h>
int findIndex(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}
struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int* postIndex) {
    if (inStart > inEnd)
        return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = postorder[*postIndex];
    root->left = root->right = NULL;
    (*postIndex)--;
    // If only one node
    if (inStart == inEnd)
        return root;

    // Find root index in inorder
    int inIndex = findIndex(inorder, inStart, inEnd, root->val);

    // Build right first, then left
    root->right = build(inorder, inIndex + 1, inEnd, postorder, postIndex);
    root->left  = build(inorder, inStart, inIndex - 1, postorder, postIndex);

    return root;
}

// Main function
struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {
    
    int postIndex = postorderSize - 1;
    return build(inorder, 0, inorderSize - 1, postorder, &postIndex);
}
