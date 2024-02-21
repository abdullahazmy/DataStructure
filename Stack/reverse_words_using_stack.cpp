#include <iostream>
#include <stack>
using namespace std;

string reverse_string(string s)
{
    s += ' ';
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            while (!st.empty())
            {
                ans += st.top();
                st.pop();
            }
            ans += ' ';
        }
        else
            st.emplace(s[i]);
    }

    return ans;
}

int main()
{
    string s = "abc d efg xy";
    // getline(cin, s);
    cout << reverse_string(s);
}
