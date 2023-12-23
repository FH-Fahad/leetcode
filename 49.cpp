// https://leetcode.com/problems/group-anagrams/

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (auto i : strs)
        {
            string current = i;
            sort(current.begin(), current.end());
            mp[current].push_back(i);
        }
        vector<vector<string>> res;
        for (auto i : mp)
        {
            res.push_back(i.second);
        }
        return res;
    }
};