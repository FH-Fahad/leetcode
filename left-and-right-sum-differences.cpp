// https://leetcode.com/problems/left-and-right-sum-differences/

class Solution
{
public:
    vector<int> leftRigthDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftSum(n);
        vector<int> rightSum(n);

        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                leftSum[i] = nums[i];
            else
                leftSum[i] = leftSum[i - 1] + nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (i == n - 1)
                rightSum[i] = nums[i];
            else
                rightSum[i] = rightSum[i + 1] + nums[i];
        }

        vector<int> answer(n);
        for (int i = 0; i < n; i++)
            answer[i] = abs(leftSum[i] - rightSum[i]);
        return answer;
    }
};