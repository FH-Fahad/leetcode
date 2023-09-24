// https://leetcode.com/problems/palindrome-number/

// solution 1:
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
        {
            return false;
        }
        int number = x;
        long long reverse = 0;
        while (number > 0)
        {
            reverse = reverse * 10 + number % 10;
            number /= 10;
        }
        return x == reverse;
    }
};

// solution 2:
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        if (x != 0 && x % 10 == 0)
            return false;

        int rightHalf = 0;
        while (x > rightHalf)
        {
            rightHalf = rightHalf * 10 + x % 10;
            x /= 10;
        }
        return x == rightHalf || x == rightHalf / 10;
    }
};