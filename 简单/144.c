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
 //前序遍历
void head(struct TreeNode* root, int* arr,int *index) {
    if(root) {
        arr[*index] = root->val;
        (*index)++;
        head(root->left,arr,index);
        head(root->right,arr,index);
    }
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    //空树
    *returnSize = 0;
    if(root == NULL) {
        return NULL;
    }
    
    int index = 0;
    int *arr = (int*)malloc(sizeof(int) * 100);
    head(root,arr,&index);
    *returnSize = index;
    return arr;
}