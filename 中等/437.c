/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

long long  dfs(struct TreeNode* tree,long long targetSum) {
    if(tree == NULL) {
        return 0;
    }
    long long s = 0;
    if(tree->val == targetSum) {
        s++;
    }
    s += dfs(tree->left,targetSum - tree->val);
    s += dfs(tree->right,targetSum - tree->val);
    return s;
}
int pathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL) {
        return 0;
    }
    int s = 0;
    s += dfs(root,targetSum) + pathSum(root->left,targetSum) + pathSum(root->right,targetSum);
    return s;
}