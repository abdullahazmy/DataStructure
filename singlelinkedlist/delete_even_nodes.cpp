#include <iostream>
using namespace std;
struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data) {}
};

/*
@ Node *get_backnth(int idx);     done
@ void delete_node(Node *node);   done
@ void delete_front();             done
@ void delete_end();               done
@ void delete_nxt(Node *node);
@ bool is_same(const singleLinkedList &other);
@ void delete_node_with_key(int key);
@@ Destructor to delete all created nodes
@@ void swap_pairs();
-------------------------------------------

# void reverse();    // reverse list nodes by adereseases
# void delete_evenidx();   // Note positions not values
# void insert_sorted(int val);

*/

class linkedlist
{
private:
    Node *head{};
    Node *tail{};
    int length{};
    void check()
    {
        if (!head)
            head = tail = nullptr;
        if (length == 1)
        {
            head = tail;
            head->next = tail->next = nullptr;
        }
        tail->next = nullptr;
    }

    void delete_node(Node *node);

public:
    void insert_end(int val);
    void insert_front(int val);
    Node *get_backnth(int idx);
    void delete_front();
    void delete_tail();
    void delete_node_with_key(int key);
    bool is_same(const linkedlist &other);
    void swap_pairs();
    void reverse();
    void delete_and_link(Node *node);
    void delete_evenpos();
    void print();
    ~linkedlist()
    {
        Node *cur = head;
        while (cur)
        {
            cur = cur->next;
            delete_front();
        }
    }
};

void linkedlist::insert_end(int val)
{
    Node *item = new Node(val);
    if (!head)
        head = tail = item;
    else
    {
        tail->next = item;
        tail = item;
        tail->next = nullptr;
    }
    length++;
}

void linkedlist::insert_front(int val)
{
    Node *item = new Node(val);
    if (!head)
        head = tail = item;
    else
    {
        Node *tmp = head;
        head = item;
        head->next = tmp;
    }
    length++;
}

Node *linkedlist::get_backnth(int idx)
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

void linkedlist::delete_node(Node *node)
{
    delete (node);
    length--;
}

void linkedlist::delete_front()
{
    if (!head)
        return;
    if (length == 1)
    {
        delete_node(head);
        head = tail = nullptr;
        return;
    }

    Node *tmp = head;
    head = head->next;
    delete_node(tmp);
}

void linkedlist::delete_tail()
{
    if (!head)
        return;
    if (length == 1)
    {
        delete_node(tail);
        head = tail = nullptr;
    }

    else
    {
        Node *tmp = tail;
        for (Node *cur = head; cur; cur = cur->next)
        {
            if (cur->next == tail)
            {
                tail = cur;
                break;
            }
        }
        delete_node(tmp);
        check();
    }
}

void linkedlist::delete_node_with_key(int key)
{
    if (!head)
        return;
    if (head->data == key)
    {
        delete_front();
    }

    else if (tail->data == key)
    {
        delete_tail();
    }

    else
        for (Node *cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next)
        {
            Node *tmp = cur;
            if (cur->data == key)
            {
                prv->next = cur->next;
                delete_node(tmp);
                return;
            }
        }
}

bool linkedlist::is_same(const linkedlist &other)
{
    Node *cur = head;
    Node *tmp = other.head;
    if (length != other.length)
        return false;
    while (cur)
    {
        if (cur->data != tmp->data)
            return false;
        cur = cur->next, tmp = tmp->next;
    }
    return true;
}

void linkedlist::swap_pairs()
{
    // Check if the list is empty or has only one node
    if (!head || !head->next)
        return;

    // Traverse the list by pairs
    for (Node *cur = head; cur && cur->next; cur = cur->next->next)
    {
        // Swap data of current and next nodes
        int temp = cur->data;
        cur->data = cur->next->data;
        cur->next->data = temp;
    }
}

void linkedlist::reverse()
{
    if (length <= 1)
        return;
    tail = head;
    Node *prv = head;
    head = head->next;
    while (head)
    {
        Node *nxt = head->next;
        head->next = prv;

        prv = head;
        head = nxt;
    }
    head = prv;
    tail->next = nullptr;
}

void linkedlist::delete_and_link(Node *node)
{
    if (node == head)
        delete_front();
    else if (node == tail)
        delete_tail();
    else
    {
        for (Node *cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next)
        {
            if (cur == node)
            {
                prv->next = cur->next;
                delete_node(node);
            }
        }
    }
}

void linkedlist::delete_evenpos()
{
    if (length <= 1)
        return;
    int ctr = 1;
    for (Node *cur = head, *prv = head; cur; prv = cur, cur = cur->next)
    {
        if (ctr % 2 == 0)
        {

            if (cur == tail)
            {
                delete_tail();
                return;
            }
            else
            {
                prv->next = cur->next;
                delete_node(cur);
            }
            cur = prv;
        }

        ctr++;
    }
}

/// @brief /////////////////////////
void linkedlist::print()
{
    for (Node *cur = head; cur; cur = cur->next)
    {
        cout << cur->data << " ";
    }
    cout << "\n";
}

int main()
{
    linkedlist ll;
    ll.insert_end(1);
    ll.insert_end(2);
    ll.insert_end(3);
    ll.insert_end(4);
    ll.delete_evenpos();
    ll.print();
}
