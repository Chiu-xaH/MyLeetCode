/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //思路：如果结点有右孩子 展示右孩子
 //如果结点无右孩子有左孩子 展示左孩子
 //如果结点无右孩子无左孩子（叶子） 谁也不展示
void order(struct TreeNode* root,int *arr,int *size,int height) {
    if(root == NULL) return;
    if(height == *size) {
        arr[(*size)++] = root->val;
    }
    order(root->right,arr,size,height+1);
    order(root->left,arr,size,height+1);
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* arr = (int*)malloc(sizeof(int)*100);
    order(root,arr,returnSize,0);
    return arr;
}