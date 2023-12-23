// https://leetcode.com/problems/reverse-integer/

class Solution
{
public:
    int reverse(int x)
    {
        const int MY_INT_MAX = 2147483647;
        const int MY_INT_MIN = -2147483648;

        int sign = (x < 0) ? -1 : 1;

        long long abs_x = static_cast<long long>(abs(x));

        long long reversed_x = 0;
        while (abs_x != 0)
        {
            int digit = abs_x % 10;
            abs_x /= 10;

            if (reversed_x > (MY_INT_MAX - digit) / 10)
                return 0;

            reversed_x = reversed_x * 10 + digit;
        }

        reversed_x *= sign;

        if (reversed_x > MY_INT_MAX || reversed_x < MY_INT_MIN)
            return 0;

        return static_cast<int>(reversed_x);
    }
};