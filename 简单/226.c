void PreOrder(struct TreeNode * root) {
    if(root) {
        struct TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

struct TreeNode* invertTree(struct TreeNode* root) {
    PreOrder(root);
    return root;
}