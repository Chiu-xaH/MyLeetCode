void preOrder(struct TreeNode* tree, struct TreeNode** pre) {
    if (tree == NULL) {
        return;
    }
    // 逆前序
    preOrder(tree->right, pre);
    preOrder(tree->left, pre);

    tree->right = *pre; 
    tree->left = NULL;  
    *pre = tree;      
}

void flatten(struct TreeNode* root) {
    struct TreeNode* pre = NULL;
    preOrder(root, &pre);
}
