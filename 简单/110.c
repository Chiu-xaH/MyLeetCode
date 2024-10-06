/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a,int b) {
    return a > b ? a : b;
}

int Height(struct TreeNode* root) {
    if(root) {
        return 1 + max(Height(root->left),Height(root->right));
    } else return 0;
}

int BH(struct TreeNode* root) {
    int left = Height(root->left);
    int right = Height(root->right);
    return left - right;
}

bool isBalanced(struct TreeNode* root) {
    if (!root) return true;
    int bh = BH(root);
    bool structEqual = isBalanced(root->left) && isBalanced(root->right);
    return (fabs(bh) <= 1) && structEqual;
}