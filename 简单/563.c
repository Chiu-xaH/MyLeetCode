 //分析此题，明显用递归思想
 //累计每个坡度
 int num = 0;
 int totalSum(struct TreeNode* tree) {
    if(!tree) return 0;
    int left = totalSum(tree->left);
    int right = totalSum(tree->right);

    num += fabs(left-right);
    //子树总和值
    return left + right + tree->val;
 } 
int findTilt(struct TreeNode* root) {
    num = 0;
    totalSum(root);
    return num;
}