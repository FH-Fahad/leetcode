// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        size_t found = haystack.find(needle);
        if (found != string::npos)
            return found;

        else
            return -1;
    }
};