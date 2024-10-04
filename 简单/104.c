
// * Definition for a binary tree node.
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };

int max(int m,int n) {
    return m > n ? m : n;
}
int maxDepth(struct TreeNode* root) {
    if(root) {
        return 1 + max(maxDepth(root->left),maxDepth(root->right));
    } else {
        return 0;
    }
}