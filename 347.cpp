// https://leetcode.com/problems/top-k-frequent-elements/

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;

        for (auto i : nums)
        {
            mp[i]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto i : mp)
        {
            pq.push({i.second, i.first});
        }
        vector<int> res;
        while (k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};