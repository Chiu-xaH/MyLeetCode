/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//设计算法以求解编号为i和j的两个结点的最近的公共祖先结点
struct TreeNode* lowestCommonAncestor(struct TreeNode* T, struct TreeNode* I, struct TreeNode* J) {
    if (T == NULL || T == I || T == J) {
        return T;
    }

    struct TreeNode* left = lowestCommonAncestor(T->left, I, J);
    struct TreeNode* right = lowestCommonAncestor(T->right, I, J);

    // 目标在左子树和右子树，第一次发现此点即为最近公共祖先
    if (left && right) {
        return T;
    }
    // 否则返回非空的子树，两个目标都在那边
    return left ? left : right;
}