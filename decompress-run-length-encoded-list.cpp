// https://leetcode.com/problems/decompress-run-length-encoded-list/

class Solution
{
public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        vector<int> decompressed_list;

        for (int i = 0; i < nums.size(); i += 2)
        {
            int freq = nums[i];
            int val = nums[i + 1];

            for (int j = 0; j < freq; j++)
            {
                decompressed_list.push_back(val);
            }
        }

        return decompressed_list;
    }
};
