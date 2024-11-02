/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 int max(int a,int b) {
    return a > b ? a : b;
 }
 int height(struct TreeNode* root) {
    if(root == NULL) return 0;
    return max(height(root->left),height(root->right))+1;
 }
 void order(struct TreeNode* root,int *num,int hei,int cur) {
    if(root ==NULL) return;
    if(hei == cur) *num = root->val;
    
    order(root->right,num,hei,cur+1);
    order(root->left,num,hei,cur+1);
 }
int findBottomLeftValue(struct TreeNode* root) {
    int num;
    order(root,&num,height(root),1);
    return num;
}