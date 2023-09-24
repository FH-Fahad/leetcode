// https://leetcode.com/problems/maximum-product-subarray/

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxProduct = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];

        for (int i = 1; i < nums.size(); ++i)
        {
            int temp = currentMax;
            currentMax = max(nums[i], max(currentMax * nums[i], currentMin * nums[i]));
            currentMin = min(nums[i], min(temp * nums[i], currentMin * nums[i]));
            maxProduct = max(maxProduct, currentMax);
        }
        return maxProduct;
    }
};