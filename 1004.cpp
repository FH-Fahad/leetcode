// https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {

        int left = 0;
        int count = 0;
        int window = 0;
        int leftIndex = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            if (nums[right] == 0)
            {
                count++;
            }
            while (count > k)
            {
                if (nums[left] == 0)
                {
                    count--;
                }
                left++;
            }
            if (right - left + 1 > window)
            {
                window = right - left + 1;
                leftIndex = left;
            }
        }

        if (window == 0)
        {
            return window;
        }
        return window;
    }
};