void flatten(struct TreeNode* root) {
    struct TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left != NULL) {
            
            struct TreeNode* prev = curr->left;
            while (prev->right != NULL) {
                prev = prev->right;
            }

            
            prev->right = curr->right;

            // Move left subtree to right
            curr->right = curr->left;
            curr->left = NULL;
        }
        // Move to next node
        curr = curr->right;
    }
}
