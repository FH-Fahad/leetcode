// https://leetcode.com/problems/search-a-2d-matrix/


// Solution 1
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = (m > 0) ? matrix[0].size() : 0;

        vector<int> nums;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                nums.push_back(matrix[i][j]);
            }
        }

        int l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
            {
                return true;
            }
            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
};


// Solution 2
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = (m > 0) ? matrix[0].size() : 0;

        int l = 0, r = m * n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            int mid_val = matrix[mid / n][mid % n];

            if (mid_val == target)
            {
                return true;
            }
            else if (mid_val < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return false;
    }
};