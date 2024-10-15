bool PreOrder(struct TreeNode* tree,int value) {
    if(tree != NULL) {
        if(tree->val != value) return false;
        return PreOrder(tree->left,value) && PreOrder(tree->right,value);
    }
    return true;
}

bool isUnivalTree(struct TreeNode* root) {
    int value = root->val;
    return PreOrder(root,value);
}