// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max = INT_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (prices[i] < max)
            {
                max = prices[i];
            }
            else if (prices[i] - max > ans)
            {
                ans = prices[i] - max;
            }
        }
        return ans;
    }
};