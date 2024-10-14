/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。
//两节点之间路径的 长度 由它们之间边数表示。


 //思路：直径=根左子树高度+根右子树高度
 //子树高度用递归或者遍历思想
 int max(int a,int b) {
    return a > b ? a : b;
 }
int Height(struct TreeNode* root,int *dis) {
    if(root) {
        int left = Height(root->left,dis);
        int right = Height(root->right,dis);
        *dis = max(*dis,left+right);
        return 1 + max(left,right);
    } else return 0;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    int dis = 0;
    Height(root,&dis);
    return dis;
}