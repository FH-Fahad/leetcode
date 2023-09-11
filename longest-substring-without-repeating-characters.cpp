// https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.length();
        int max_length = 0, l = 0, r = 0;
        unordered_set<char> char_set;

        while (r < n)
        {
            if (char_set.find(s[r]) == char_set.end())
            {
                char_set.insert(s[r]);
                max_length = max(max_length, r - l + 1);
                r++;
            }
            else
            {
                char_set.erase(s[l]);
                l++;
            }
        }
        return max_length;
    }
};