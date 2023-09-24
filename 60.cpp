// https://leetcode.com/problems/permutation-sequence/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string result;
        vector<int> nums;

        for (int i = 1; i <= n; i++)
        {
            nums.push_back(i);
        }

        k--;
        int fact = 1;
        for (int i = 1; i <= n; i++)
        {
            fact *= i;
        }

        for (int i = 0; i < n; i++)
        {
            fact /= (n - i);
            int index = k / fact;
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);
            k %= fact;
        }

        return result;
    }
};