/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 //思路：先找到x和y结点的父节点，父节点不同但深度相同则为堂兄弟
struct TreeNode* PreOrder(struct TreeNode* root,struct TreeNode* parent,int a) {
    if(root) {
        if(root->val == a) {
            return parent;
        }
        if(PreOrder(root->left,root,a)) return PreOrder(root->left,root,a);
        return PreOrder(root->right,root,a);
    }
    return NULL;
}
int Height(struct TreeNode* root,int a) {
    if (root == NULL) return -1;
    if (root->val == a) return 0;
    int leftHeight = Height(root->left,a);
    if (leftHeight != -1) return leftHeight + 1;

    int rightHeight = Height(root->right, a);
    if (rightHeight != -1) return rightHeight + 1;

    return -1;
}

bool isCousins(struct TreeNode* root, int x, int y) {
    struct TreeNode* parentX = PreOrder(root,NULL,x);
    struct TreeNode* parentY = PreOrder(root,NULL,y);
    if(parentX != parentY && Height(root,x) == Height(root,y)) {
        return true;
    } else {
        return false;
    }
}