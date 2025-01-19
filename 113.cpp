// https://leetcode.com/problems/path-sum-ii/

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, targetSum, path, res);
        return res;
    }

    void dfs(TreeNode *root, int targetSum, vector<int> &path, vector<vector<int>> &res)
    {
        if (root == NULL)
            return;

        path.push_back(root->val);
        targetSum -= root->val;

        if (root->left == NULL && root->right == NULL && targetSum == 0)
            res.push_back(path);

        dfs(root->left, targetSum, path, res);
        dfs(root->right, targetSum, path, res);
        path.pop_back();
    }
};