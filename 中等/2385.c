class Solution {
public:
    using IntTreeNode = TreeNode;
    int DfsTree(IntTreeNode* root, int start, int use_time, bool& visit, int& res, int& start_deep, int cur_deep)
    {
        if (!root)return 0;

        if (root->val == start)
        {
            visit = true;
            start_deep = cur_deep;
        }

        auto last_visit = visit;
        //当前节点是start的子节点或者同属于一个子树
        if (last_visit && !(root->val == start))
        {
            ++use_time;
            res = max(use_time, res);
        }

        auto left_deep = DfsTree(root->left, start, use_time, visit, res, start_deep, cur_deep+1);
        auto left_vist = visit;
        //start在左子树
        if (!last_visit && left_vist)
        {
            use_time += start_deep-cur_deep;
            res = max(use_time, res);
        }

        auto right_deep = DfsTree(root->right, start, use_time, visit, res, start_deep, cur_deep + 1);
        auto right_visit = visit;
        //start在右子树
        if (!left_vist && right_visit)
        {
            use_time += left_deep + start_deep - cur_deep;
            res = max(use_time, res);
        }
        
        //返回当前子树的深度
        return max(right_deep, left_deep) + 1;
    }

    int amountOfTime(IntTreeNode* root, int start)
    {
        int res{ 0 }, use_time{ 0 }, start_deep{ 0 };
        bool visit{ false };
        DfsTree(root, start, use_time, visit, res, start_deep,0);
        return res;
    }
};