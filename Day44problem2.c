/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void preorder(struct TreeNode* root, int* arr, int* index) {
    if (root == NULL) return;
    arr[*index] = root->val;
    (*index)++;
    preorder(root->left, arr, index);
    preorder(root->right, arr, index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100 * sizeof(int));  // max nodes constraint
    int index = 0;
    preorder(root, arr, &index);

    *returnSize = index;
    return arr;
}
