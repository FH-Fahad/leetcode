// https://leetcode.com/problems/is-subsequence/

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s == t)
            return true;

        int n = s.length(), m = t.length(), j = 0;

        for (int i = 0; i < m; i++)
        {
            if (s[j] == t[i])
                j++;
            if (j == n)
                return true;
        }
        return false;
    }
};