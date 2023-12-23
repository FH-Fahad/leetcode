// https://leetcode.com/problems/longest-palindromic-substring/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string res = "";
        int resLen = 0, len = s.size();

        for (int i = 0; i < len; i++)
        {
            int l = i, r = i;
            while (l >= 0 and r < len and s[l] == s[r])
            {
                if ((r - l + 1) > resLen)
                {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
            l = i, r = i + 1;
            while (l >= 0 and r < len and s[l] == s[r])
            {
                if ((r - l + 1) > resLen)
                {
                    res = s.substr(l, r - l + 1);
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return res;
    }
};
