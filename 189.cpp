// https://leetcode.com/problems/rotate-array/

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        vector<int> rotated(n);

        for (int i = 0; i < k; i++)
            rotated[i] = nums[n - k + i];

        for (int i = k; i < n; i++)
            rotated[i] = nums[i - k];

        nums = rotated;

        for (auto &i : nums)
            cout << i << " ";
    }
};
