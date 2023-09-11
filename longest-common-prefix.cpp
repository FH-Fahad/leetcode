// https://leetcode.com/problems/longest-common-prefix/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }
        string lcp = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            int j = 0;
            while (j < lcp.length() && j < strs[i].length() && lcp[j] == strs[i][j])
            {
                j++;
            }
            lcp = lcp.substr(0, j);
            if (lcp.empty())
            {
                return lcp;
            }
        }
        return lcp;
    }
};