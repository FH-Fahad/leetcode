// https://leetcode.com/problems/daily-temperatures/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        stack<int> st;
        vector<int> answer(n, 0);

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int x = st.top();
                st.pop();
                answer[x] = i - x;
            }
            st.push(i);
        }
        return answer;
    }
};
