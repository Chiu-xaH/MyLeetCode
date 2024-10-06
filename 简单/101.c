/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isMirror(struct TreeNode* left,struct TreeNode* right) {
    if(left == NULL && right == NULL) {
        return true;
    } else if(left != NULL && right == NULL) {
        return false;
    } else if(left == NULL && right != NULL) {
        return false;
    } else  {
        //核心思想：细化成最小子问题
        //左子树的左子树对称为右子树的右子树，左子树的右子树对称为右子树的左子树
        bool structEqual = isMirror(left->left,right->right) && isMirror(right->left,left->right);
        bool valEqual = (left->val == right->val);
        return valEqual && structEqual;
    }
}

bool isSymmetric(struct TreeNode* root) {
    if(root) {
       return isMirror(root->left,root->right);
    }
    return true;
}