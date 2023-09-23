// https://leetcode.com/problems/permutations-ii/

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());

        backtrack(nums, current, used, result);

        return result;
    }

private:
    void backtrack(vector<int> &nums, vector<int> &current, vector<bool> &used, vector<vector<int>> &result)
    {
        if (current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
            {
                continue;
            }

            current.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, current, used, result);
            used[i] = false;
            current.pop_back();
        }
    }
};