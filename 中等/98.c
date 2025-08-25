/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

// bool isValidBST(struct TreeNode* root) {
//     if(root == NULL) {
//         return true;
//     }
//     bool l = true;
//     if(root->left) {
//         l = root->left->val < root->val;
//     } 
//     bool r = true;
//     if(root->right) {
//         r = root->right->val > root->val;
//     } 
//     if(l && r) {
//         return isValidBST(root->left) && isValidBST(root->right);
//     } else {
//         return false;
//     }
// }

bool helper(struct TreeNode* root, long min, long max) {
    if (root == NULL) return true;
    if (root->val <= min || root->val >= max) return false;
    return helper(root->left, min, root->val) && helper(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
}