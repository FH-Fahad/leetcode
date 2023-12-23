// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m == 0 && n == 0)
        {
            return 0.0;
        }

        vector<int> answer;
        int a = 0, b = 0;

        while (a != m && b != n)
        {
            if (nums1[a] < nums2[b])
            {
                answer.push_back(nums1[a]);
                a++;
            }
            else
            {
                answer.push_back(nums2[b]);
                b++;
            }
        }
        while (a != m)
        {
            answer.push_back(nums1[a++]);
        }
        while (b != n)
        {
            answer.push_back(nums2[b++]);
        }

        int total = answer.size();
        if (total % 2 == 1)
        {
            return static_cast<double>(answer[total / 2]);
        }
        else
        {
            int r = total / 2;
            return (static_cast<double>(answer[r - 1]) + static_cast<double>(answer[r])) / 2.0;
        }
    }
};
