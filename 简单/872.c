/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void PreOrder(struct TreeNode* tree,int* leafList,int *size) {
    if(tree) {
        if(tree->left == NULL && tree->right == NULL) {
            leafList[*size] = tree->val;
            (*size)++;
        }
        PreOrder(tree->left,leafList,size);
        PreOrder(tree->right,leafList,size);
    }
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int leafList1[199];
    int leafList2[199];
    int size1 = 0,size2 = 0;
    PreOrder(root1,leafList1,&size1);
    PreOrder(root2,leafList2,&size2);
    if(size1 == size2) {
        for(int i = 0;i < size1;i++) {
            if(leafList1[i] != leafList2[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}