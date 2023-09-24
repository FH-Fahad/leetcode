// https://leetcode.com/problems/squares-of-a-sorted-array/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> nums2;
        for (auto &i : nums)
        {
            nums2.push_back(abs(i * i));
        }
        sort(nums2.begin(), nums2.end());
        return nums2;
    }
};