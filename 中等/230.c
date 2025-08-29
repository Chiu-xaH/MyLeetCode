/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void midOrder(struct TreeNode* tree, int* k, int* value) {
    if (tree == NULL) {
        return;
    }

    midOrder(tree->left, k, value);

    // 每访问一个节点，k减1
    (*k)--;
    if (*k == 0) {
        *value = tree->val;
        return; // 已找到
    }

    midOrder(tree->right, k, value);
}
int kthSmallest(struct TreeNode* root, int k) {
    int min;
    midOrder(root,&k,&min);
    return min;
}