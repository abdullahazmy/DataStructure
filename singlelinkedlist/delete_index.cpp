#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int data) : data(data) {}
};

class singleLinkedList
{
private:
    Node *head{};
    Node *tail{};
    int length{};
    void check();
    void delete_node(Node *node);

public:
    void insert(int val);
    void print();
    Node *get_nth(int idx);
    void delete_nth(int idx);
};

void singleLinkedList::check()
{
    if (length == 0)
        head = tail = nullptr;
    else if (length == 1)
    {
        head = tail;
        head->next = tail->next = nullptr;
    }

    else if (length == 2)
    {
        head->next->next = tail->next;
    }
}

void singleLinkedList::insert(int val)
{
    Node *item = new Node(val);
    if (!head)
    {
        head = tail = item;
        length++;
        check();
    }
    else
    {
        tail->next = item;
        tail = item;
        length++;
        check();
    }
}

void singleLinkedList::print()
{
    for (Node *cur = head; cur; cur = cur->next)
    {
        cout << cur->data << " ";
    }
    cout << "\n";
}

Node *singleLinkedList::get_nth(int idx)
{
    int ctr = 0;
    for (Node *cur = head; cur; cur = cur->next)
    {
        if (idx == ctr)
            return cur;
        ctr++;
    }
    return nullptr;
}

void singleLinkedList::delete_node(Node *node)
{
    delete node;
    length--;
    check();
}

void singleLinkedList::delete_nth(int idx)
{
    Node *prv = get_nth(idx - 1);
    Node *cur = prv->next;
    bool is_tail = (cur == tail);
    if (is_tail)
    {
        tail = prv;
    }
    prv->next = cur->next;
    delete_node(cur);
}

int main()
{
    singleLinkedList list1;
    list1.insert(50);
    list1.insert(70);
    list1.insert(90);
    list1.delete_nth(1);
    list1.print();
}
