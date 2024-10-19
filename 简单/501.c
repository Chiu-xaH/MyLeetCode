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
 //二叉搜索树中的众数
//统计树的结点数
void count(struct TreeNode* root,int *num) {
    if(root) {
        (*num)++;
        count(root->left,num);
        count(root->right,num);
    }
}

void inorder(struct TreeNode* root, int* prev, int* count, int* maxCount, int* result, int* returnSize) {
    if (root == NULL) return;
    
    inorder(root->left, prev, count, maxCount, result, returnSize);
    
    if (*prev == root->val) {
        (*count)++;  // 当前值与前一个值相同，计数加1
    } else {
        *count = 1;  // 否则重置计数
    }
    
    if (*count > *maxCount) {
        *maxCount = *count;
        *returnSize = 1;  // 更新最大计数，并将结果数组重置
        result[0] = root->val;
    } else if (*count == *maxCount) {
        result[*returnSize] = root->val;  // 如果当前计数等于最大计数，保存当前值
        (*returnSize)++;
    }
    
    *prev = root->val;  // 更新前一个值为当前值
    
    inorder(root->right, prev, count, maxCount, result, returnSize);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if (root == NULL) return NULL;
    
    int counts = 0;
    count(root, &counts); 
    
    int* result = (int*)malloc(sizeof(int) * counts);  // 动态分配空间，存储结果
    
    int prev = 0;
    int count = 0;
    int maxCount = 0;
    
    inorder(root, &prev, &count, &maxCount, result, returnSize);  // 中序遍历
    
    return result;
}