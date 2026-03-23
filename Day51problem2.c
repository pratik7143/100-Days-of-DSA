struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    while (root != NULL) {
        
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        // If both nodes are greater, go right
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        // Otherwise, this is the split point (LCA)
        else {
            return root;
        }
    }
    return NULL;
}
