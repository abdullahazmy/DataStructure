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
    void insert_front(int val);
    void delete_front();
    Node *get_backnth(int idx); // reversed
    bool is_same(const singleLinkedList &other);
    bool is_same2(const singleLinkedList &other);
    ~singleLinkedList()
    {
        Node *cur = head;
        Node *nxt;
        while (cur)
        {
            nxt = cur->next;
            delete (cur);
            cur = nxt;
        }
        head = nullptr;
    }
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
    check();
}

void singleLinkedList::insert_front(int val)
{
    Node *item = new Node(val);
    item->next = head;
    head = item;
    length++;
    check();
}

void singleLinkedList::delete_front()
{
    if (!head)
        head = nullptr;
    else
    {
        Node *cur = head;
        head = cur->next;
        delete_node(cur);
    }
}

Node *singleLinkedList::get_backnth(int idx)
{
    if (length < idx)
        return nullptr;
    return get_nth(length - idx);
}

bool singleLinkedList::is_same(const singleLinkedList &other)
{
    if (length != other.length)
        return false;
    Node *second = other.head;
    for (Node *cur = head; cur; cur = cur->next)
    {
        if (cur->data != second->data)
            return false;
        second = second->next;
    }
    return true;
}

// Not using length variable
bool singleLinkedList::is_same2(const singleLinkedList &other)
{
    Node *cur = head, *other_h = other.head;
    while (cur && other_h)
    {
        if (cur->data != other_h->data)
            return false;
        cur = cur->next, other_h = other_h->next;
    }

    return (!cur && !other_h);
}

int main()
{
    singleLinkedList list1;
    list1.insert(50);
    list1.insert(70);
    list1.insert(90);
    singleLinkedList list2;
    list2.insert(50);
    list2.insert(70);
    list2.insert(90);
    cout << list1.is_same2(list2);
}
