// https://leetcode.com/problems/string-to-integer-atoi/

class Solution
{
public:
    int myAtoi(string s)
    {
        int result = 0, sign = 1;
        bool foundDigit = false;

        size_t i = 0;
        while (i < s.length() && s[i] == ' ')
            i++;

        if (i < s.length() && (s[i] == '+' || s[i] == '-'))
            sign = (s[i++] == '-') ? -1 : 1;

        while (i < s.length() && isdigit(s[i]))
        {
            int digit = s[i++] - '0';

            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10))
                return (sign == 1) ? INT_MAX : INT_MIN;

            result = result * 10 + digit;
            foundDigit = true;
        }
        if (!foundDigit && (i == s.length() || s[i] != '.'))
            return 0;

        return (foundDigit) ? sign * result : 0;
    }
};