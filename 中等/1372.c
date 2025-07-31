int max(int a, int b) {
    return a > b ? a : b;
}

typedef struct Result {
    int left;
    int right;
} Result;

Result dfs(struct TreeNode* root, int* maxLen) {
    if (root == NULL) {
        return (Result){-1, -1};
    }

    Result leftRes = dfs(root->left, maxLen);
    Result rightRes = dfs(root->right, maxLen);

    int left = leftRes.right + 1;  // 当前节点向左走，下一步要右
    int right = rightRes.left + 1; // 当前节点向右走，下一步要左

    *maxLen = max(*maxLen, max(left, right));

    return (Result){left, right};
}

int longestZigZag(struct TreeNode* root) {
    int maxLen = 0;
    dfs(root, &maxLen);
    return maxLen;
}
