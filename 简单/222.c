/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void PreOrder(struct TreeNode *root,int *count) {
    if(root) {
        (*count)++;
        PreOrder(root->left,count);
        PreOrder(root->right,count);
    }
}

int countNodes(struct TreeNode* root) {
    int count = 0;
    PreOrder(root,&count);
    return count;
}