/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int findSecondMinimumValue(struct TreeNode* root) {
    if(root == NULL) return -1;
    if(root->left && root->right) {
        int left = root->left->val == root->val ? findSecondMinimumValue(root->left) : root->left->val;
        int right = root->right->val == root->val ? findSecondMinimumValue(root->right) : root->right->val;
        if(left == -1) return right;
        if(right == -1) return left;
        return left < right ? left : right;
    } else {
        return -1;
    }
}