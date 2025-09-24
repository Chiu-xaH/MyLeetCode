/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void dfs(struct TreeNode* node, long long cur, long long *ans) {
    if (!node) {
        return;
    }
    cur = cur * 10 + node->val;
    // 如果是叶子节点，累加
    if (!node->left && !node->right) {
        *ans += cur;
        return;
    }
    if (node->left) dfs(node->left, cur, ans);
    if (node->right) dfs(node->right, cur, ans);
}

int sumNumbers(struct TreeNode* root){
    if (!root) {
        return 0;
    }

    long long ans = 0;
    dfs(root, 0, &ans);
    
    return (int)ans; 
}