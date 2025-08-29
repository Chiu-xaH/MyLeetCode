/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int length = preorderSize;
    if(length == 0) return NULL;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    // 中序中寻找根结点
    int ptr = 0;
    while(ptr < length && inorder[ptr] != root->val) {
        ptr++;
    }
    int leftLength = ptr;
    int rightLength = length-1-ptr;
    root->left = buildTree(preorder+1,leftLength,inorder,leftLength);
    root->right = buildTree(preorder+1+ptr,rightLength,inorder+ptr+1,rightLength);
    return root;
}