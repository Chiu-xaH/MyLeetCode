/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

  // 要删的结点1.只有左孩子2.只有右孩子3.左右孩子都有4.叶子
 /*
 1、2 孩子上位
 4 直接删
 3 找到该节点的右子树的最小节点（或左子树的最大节点），然后用这个节点的值替代当前节点的值，最后递归删除该节点（替代节点所在位置的节点）。
  */

typedef struct TreeNode* Tree;

Tree findMaxOrMin(Tree tree,int* value,bool max) {
    if(tree == NULL) {
        return NULL;
    }
    if(max) {
        // 找最大值
        while (tree->right != NULL) {
            tree = tree->right;
        }
        *value = tree->val;
        return tree;
    } else {
        // 找最小值
        while (tree->left != NULL) {
            tree = tree->left;
        }
        *value = tree->val;
        return tree;
    }
}

void del(Tree* tree, int key) {
    Tree current = *tree;

    if (current == NULL) {
        return;
    }

    if (current->val == key) {
        // 要删除的节点
        if (current->left && current->right) {
            int value;
            Tree node = findMaxOrMin(current->right, &value, false);  
            current->val = value;
            del(&(current->right), value);  // 删除最小节点
        } else if (current->left && !current->right) {
            // 只有左孩子：用左孩子替代当前节点
            Tree old = current;
            *tree = current->left;  // 修改父节点的指针
            free(old);
        } else if (!current->left && current->right) {
            // 只有右孩子：用右孩子替代当前节点
            Tree old = current;
            *tree = current->right;  // 修改父节点的指针
            free(old);
        } else {
            // 叶子节点：直接删除
            free(current);
            *tree = NULL;
        }
    } else if (key < current->val) {
        // 如果key小于当前节点的值，继续在左子树中查找
        del(&(current->left), key);
    } else {
        // 如果key大于当前节点的值，继续在右子树中查找
        del(&(current->right), key);
    }
}




struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    del(&root, key); 
    return root;
}