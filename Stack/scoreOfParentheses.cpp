class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        stack<int> st;
        st.push(0);
        for (auto i : s)
        {
            if (i == '(')
                st.push(0);
            else
            {
                int last = st.top();
                st.pop();
                if (last == 0)
                    last = 1;
                else
                    last *= 2;
                int parent = last + st.top();
                st.pop();
                st.push(parent);
            }
        }

        return st.top();
    }
};
