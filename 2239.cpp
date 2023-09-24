// https://leetcode.com/problems/find-closest-number-to-zero/

class Solution
{
public:
    int findClosestNumber(vector<int> &nums)
    {
        int closest = numeric_limits<int>::max();
        int target = 0;

        for (int num : nums)
        {
            if (abs(num) < abs(closest) || (abs(num) == abs(closest) && num > target))
            {
                closest = num;
                target = num;
            }
        }
        return closest;
    }
};


