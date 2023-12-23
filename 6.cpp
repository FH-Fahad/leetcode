// https://leetcode.com/problems/zigzag-conversion/

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows <= 1)
            return s;

        string result;
        int size = 2 * numRows - 2;

        for (int i = 0; i < numRows; i++)
        {
            for (int j = i; j < s.size(); j += size)
            {
                result += s[j];
                int tmp = j + size - 2 * i;
                if (i != 0 && i != numRows - 1 && tmp < s.size())
                    result += s[tmp];
            }
        }
        return result;
    }
};