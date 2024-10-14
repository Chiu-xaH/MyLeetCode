/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //看错了，左叶子
void PreOrder(struct TreeNode* root,int *total) {
    if(root) {
        if(root->left && root->left->left == NULL && root->left->right == NULL) {
            *total += root->left->val;
        }
        PreOrder(root->left,total);
        PreOrder(root->right,total);
    }
    
}
 
int sumOfLeftLeaves(struct TreeNode* root) {
    int total = 0;
    PreOrder(root,&total);
    return total;
}