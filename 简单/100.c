/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if(p && q) {
        bool valEqual = (p->val == q->val);
        bool structEqual = isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        return valEqual && structEqual;
    } else if(!p && !q) {
        return true;
    } else {
        return false;
    }
}