// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int max = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        vector<bool> ans;
        for (int i = 0; i < n; i++)
        {
            if ((candies[i] + extraCandies) >= max)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};