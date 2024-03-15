#include <iostream>
using namespace std;

struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data) {}
};

class queue
{
private:
    int length{};
    Node *head{};
    Node *tail{};

public:
    void push(int val)
    {
        length++;
        Node *item = new Node(val);
        if (!head)
        {
            head = tail = item;
        }

        else
        {
            tail->next = item;
            tail = item;
        }
    }

    bool is_empty() { return !head; }

    int pop()
    {
        if (is_empty())
            return -1;
        length--;
        Node *tmp = head;
        int ans = tmp->data;
        head = head->next;
        delete (tmp);
        return ans;
    }

    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
        {
            cout << cur->data << " ";
        }
        cout << "\n";
    }

    int peak() { return tail->data; }
};

int main()
{
    queue q;
}
