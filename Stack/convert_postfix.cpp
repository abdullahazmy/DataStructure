#include <iostream>
using namespace std;

struct Node
{
    int data{};
    Node *prv{};
    Node(int data) : data(data) {}
};

class Stack
{
private:
    int length{};
    Node *tail{};

public:
    void push(int val)
    {
        length++;
        Node *item = new Node(val);
        item->prv = tail;
        tail = item;
    }

    int top()
    {
        return tail->data;
    }

    int pop()
    {
        length--;
        int ans = tail->data;
        Node *tmp = tail->prv;
        delete (tail);
        tail = tmp;
        return ans;
    }

    int presedence(char s) { return s == '+' || s == '-' ? 1 : 2; }

    string postfix(string s)
    {
        Stack stk;
        string ans = "";
        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (isdigit(s[i]))
                ans.push_back(s[i]);
            else
            {
                while (stk.tail && presedence(stk.top()) >= presedence(s[i]))
                    ans.push_back(stk.pop());
                stk.push(s[i]);
            }
        }

        while (stk.tail)
            ans.push_back(stk.pop());
        return ans;
    }

    ///////////////////////////////

    void print()
    {
        for (Node *cur = tail; cur; cur = cur->prv)
        {
            cout << cur->data << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Stack s;
    string tst = "1+3*5-8/2";
    cout << s.postfix(tst);

    // s.print();
}
