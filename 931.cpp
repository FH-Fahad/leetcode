// https://leetcode.com/problems/minimum-falling-path-sum

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int rows = matrix.size(), cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int j = 0; j < cols; ++j)
            dp[0][j] = matrix[0][j];

        for (int i = 1; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                dp[i][j] = matrix[i][j] + min({(j > 0) ? dp[i - 1][j - 1] : dp[i - 1][j], 
                    dp[i - 1][j], (j < cols - 1) ? dp[i - 1][j + 1] : dp[i - 1][j]});

        int result = dp[rows - 1][0];
        for (int j = 1; j < cols; ++j)
            result = min(result, dp[rows - 1][j]);

        return result;
    }
};