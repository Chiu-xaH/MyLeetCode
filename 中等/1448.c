/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int count = 0;
void dfs(struct TreeNode* tree, int max) {
    if (tree == NULL) {
        return;
    }
    if (tree->val >= max) {
        count++;
        max = tree->val; 
    }
    dfs(tree->left, max);
    dfs(tree->right, max);
}

int goodNodes(struct TreeNode* root) {
    count = 0;
    dfs(root, root->val); 
    return count;
}