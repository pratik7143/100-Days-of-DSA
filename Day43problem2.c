/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void inorder(struct TreeNode* root, int* arr, int* index)
{
    if(root == NULL)
        return;
    inorder(root->left, arr, index);   // Left
    arr[(*index)++] = root->val;       // Root
    inorder(root->right, arr, index);  // Right
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int* arr = (int*)malloc(100 * sizeof(int)); // allocate memory
    int index = 0;
    inorder(root, arr, &index);
    *returnSize = index;
    return arr;
}
