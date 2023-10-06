// https://leetcode.com/problems/minimum-window-substring/

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> S, T;

        for (char c : t)
            T[c]++;

        int left = 0, right = 0, minWinSize = INT_MAX, minWinStart = 0;
        int n = s.size(), need = T.size(), have = 0;

        while (right < n)
        {
            char current = s[right];
            S[current]++;

            if (T.count(current) && S[current] == T[current])
                have++;

            while (have == need && left <= right)
            {
                if (right - left + 1 < minWinSize)
                {
                    minWinSize = right - left + 1;
                    minWinStart = left;
                }

                char leftChar = s[left];
                S[leftChar]--;

                if (T.count(leftChar) && S[leftChar] < T[leftChar])
                    have--;
                left++;
            }
            right++;
        }
        if (minWinSize == INT_MAX)
            return "";
        else
            return s.substr(minWinStart, minWinSize);
    }
};