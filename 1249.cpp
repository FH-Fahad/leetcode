// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.size(), l = 0, r = 0;
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                l++;
                st.push(i);
            }
            else if (s[i] == ')')
            {
                if (l > 0)
                {
                    l--;
                    st.pop();
                }
                else
                {
                    s[i] = ' ';
                }
            }
        }

        while (!st.empty())
        {
            s[st.top()] = ' ';
            st.pop();
        }

        string res = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] != ' ')
            {
                res += s[i];
            }
        }
        return res;
    }
};
