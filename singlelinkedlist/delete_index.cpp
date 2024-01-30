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

public:
    void insert(int val);
    void print();
    Node *get_nth(int idx);
    // void delete_first();
    // void delete_last();
    void delete_nth(int idx);
    void check()
    {
        if (length == 0)
        {
            head = tail = nullptr;
        }
        else if (length == 1)
        {
            head = tail;
            head->next = tail->next = nullptr;
        }
    }
    void delete_node(Node *node)
    {
        delete node;
        length--;
        check();
    }
};
void singleLinkedList::insert(int val)
{
    Node *item = new Node(val);
    if (!head)
    {
        head = tail = item;
    }
    else
    {
        tail->next = item;
        tail = item;
        tail->next = nullptr;
    }
    length++;
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
        if (ctr == idx)
            return cur;
        ctr++;
    }

    return nullptr;
}

void singleLinkedList::delete_nth(int idx)
{
    Node *prev = get_nth(idx - 1);
    Node *cur = prev->next;
    bool is_tail = (cur == tail);
    if (is_tail)
    {
        tail = prev;
    }
    prev->next = cur->next;
    delete_node(cur);
}

int main()
{
    singleLinkedList list1;
    list1.insert(5);
    list1.insert(10);
    list1.insert(30);
    list1.delete_nth(1);
    list1.print();
}
