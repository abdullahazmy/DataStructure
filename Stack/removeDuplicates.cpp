#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

string removeDuplicates(string s) // abbaca
{
    stack<char> st;
    string ans = "";
    for (char c : s)
    {
        if (!st.empty() && st.top() == c)
        {
            st.pop();
        }
        else
        {
            st.emplace(c);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    cout << removeDuplicates(s);
}
