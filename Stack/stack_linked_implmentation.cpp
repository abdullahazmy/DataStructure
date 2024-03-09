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

    void pop()
    {
        length--;
        Node *tmp = tail->prv;
        delete (tail);
        tail = tmp;
    }

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
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.print();
}
