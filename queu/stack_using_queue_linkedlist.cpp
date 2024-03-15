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

    void insert_front(int val)
    {
        if (is_empty())
            push(val);
        else
        {
            Node *item = new Node(val);
            item->next = head;
            head = item;
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

class Stack
{
private:
    queue q;
    int added_elements{};

public:
    void push(int val)
    {
        q.insert_front(val);
        added_elements++;
    }

    bool is_empty() { return added_elements == 0; }

    int pop()
    {
        added_elements--;
        return q.pop();
    }
};

int main()
{
    Stack q;
    q.push(3);
    q.push(2);
    q.push(1);

    while (!q.is_empty())
    {
        cout << q.pop() << " ";
    }
}
