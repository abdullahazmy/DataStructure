#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    void insert_bottom(stack<int> St, int val)
    {
        if (St.empty())
        {
            St.emplace(val);
            return;
        }
        else
        {
            int top = St.top();
            St.pop();
            insert_bottom(St, val);
            St.emplace(top);
        }
    }

    void Reverse(stack<int> &St)
    {
        if (St.empty())
            return;
        int top = St.top();
        St.pop();
        Reverse(St);
        insert_bottom(St, top);
    }
};

int main() {}
