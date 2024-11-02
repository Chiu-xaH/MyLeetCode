struct TreeNode* pruneTree(struct TreeNode* root) {
    if(root == NULL) return root;
    
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    //按后序遍历看，就是依次移除叶子0结点，如果用前序遍历或者中序遍历麻烦的多
    if (root->val == 0 && root->left == NULL && root->right == NULL) {
        return NULL;
    }
    return root;
}