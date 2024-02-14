#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node
{
    int data;
    Node *next{};
    Node *prv{};
    Node(int data) : data(data) {}
};

class doubleLinkedList
{
private:
    Node *head{};
    Node *tail{};
    int length{};
    void check();
    void link(Node *first, Node *second);
    void add_node(Node *node);
    void delete_node(Node *cur);
    Node *delete_and_link(Node *cur);

public:
    void insert_end(int val);
    void insert_front(int val);
    void embed_after(Node *prv, int val);
    void insert_sorted(int val); // By Value
    void delete_front();
    void delete_end();
    void delete_node_with_key(int key);
    void delete_all_nodes_with_key(int k);
    void delete_even_positions();
    void delete_odd_positions();
    bool is_palindrome();
    void print();
};

void doubleLinkedList::check()
{
    if (!head)
        head = tail = nullptr;
    if (length == 1)
        head = tail;
    head->prv = nullptr;
    tail->next = nullptr;
}

void doubleLinkedList::link(Node *first, Node *second)
{
    if (first)
        first->next = second;
    if (second)
        second->prv = first;
}

////////////////////////////////////////////

void doubleLinkedList::add_node(Node *node)
{
    if (!head)
    {
        head = tail = node;
    }
    link(tail, node);
    tail = node;
    tail->next = nullptr;
    length++;
}

void doubleLinkedList::delete_node(Node *cur)
{
    if (!head)
        return;
    delete (cur);
    length--;
}

/////////////////////////////////////////////

Node *doubleLinkedList::delete_and_link(Node *cur)
{
    if (!head || !length)
        return nullptr;
    Node *prv = cur->prv;
    if (length <= 1)
    {
        delete_front();
        return nullptr;
    }

    bool is_tail = (tail == cur);
    if (is_tail)
    {
        delete_end();
        return prv;
    }
    link(cur->prv, cur->next);
    delete_node(cur);
    return prv;
}

//////////////////////////////////////////////

void doubleLinkedList::insert_end(int val)
{
    Node *item = new Node(val);
    if (!head)
    {
        head = tail = item;
        length++;
        return;
    }

    add_node(item);
}

/////////////////////////////////////////////

void doubleLinkedList::insert_front(int val)
{
    Node *item = new Node(val);
    if (!head)
    {
        head = tail = item;
        length++;
        return;
    }

    length++;
    link(item, head);
    head = item;
}

//////////////////////////////////////////////

void doubleLinkedList::embed_after(Node *prv, int val)
{
    Node *middle = new Node(val);
    length++;
    Node *cur = prv->next;
    link(prv, middle);
    link(middle, cur);
    check();
}

///////////////////////////////////////////////

void doubleLinkedList::insert_sorted(int val)
{
    if (!head || !length || head->data >= val)
        insert_front(val);
    else if (tail->data <= val)
        insert_end(val);
    else
    {
        Node *cur = head, *item = new Node(val);
        while (cur->next && cur->next->data < val)
        {
            cur = cur->next; // Move to the node whose next node's data is greater than val
        }

        // Now, cur points to the node before the insertion point
        item->next = cur->next;
        cur->next = item;
        length++;
    }
}
////////////////////////////////////////////////

void doubleLinkedList::delete_front()
{
    if (!head)
        return;
    Node *tmp = head;
    if (length <= 1)
    {
        delete_node(tmp);
        head = tail = nullptr;
        return;
    }

    head = head->next;
    delete_node(tmp);
}

/////////////////////////////////////////////////

void doubleLinkedList::delete_end()
{
    if (!head)
        return;
    Node *tmp = tail;
    if (length <= 1)
    {
        delete_node(tmp);
        head = tail = nullptr;
        return;
    }
    tail = tail->prv;
    delete_node(tmp);
    tail->next = nullptr;
}

///////////////////////////////////////////

void doubleLinkedList::delete_node_with_key(int key)
{
    if (!head)
        return;

    // If the key is found at the head, delete the head node
    if (head->data == key)
    {
        delete_front();
        return;
    }

    // If the key is found at the tail, delete the tail node

    // Traverse the list to find the node with the given key
    for (Node *cur = head; cur; cur = cur->next)
    {
        if (cur->data == key)
        {
            // Link the previous node to the next node, skipping the current node
            cur->prv->next = cur->next;
            cur->next->prv = cur->prv;

            if (cur->data == tail->data == key)
            {
                delete_end();
                return;
            }
            // Delete the current node
            delete_node(cur);
            return;
        }
    }
}

void doubleLinkedList::delete_all_nodes_with_key(int k)
{
    if (!head || !length)
        return;

    for (Node *cur = head; cur;)
    {
        if (cur->data == k)
        {
            if (length <= 1)
            {
                if (cur->data == k)
                    delete_front();
                return;
            }

            if (cur == head)
            {
                cur = cur->next;
                delete_front();
                continue;
            }

            cur = delete_and_link(cur);
        }

        else
        {
            cur = cur->next;
        }
    }
    head->prv = nullptr;
    tail->next = nullptr;
}

void doubleLinkedList::delete_even_positions()
{
    int ctr = 1;
    for (Node *cur = head; cur; cur = cur->next)
    {
        if (length <= 1)
            return;
        if (ctr % 2 == 0)
        {
            cur = delete_and_link(cur);
        }
        ctr++;
    }
}

void doubleLinkedList::delete_odd_positions()
{
    insert_front(-1); // dummy node
    delete_even_positions();
    delete_front();
}

bool doubleLinkedList::is_palindrome()
{
    Node *cur = head, *tl = tail;
    while (cur != tl)
    {
        if (cur->data != tl->data)
            return false;
        cur = cur->next;
        tl = tl->prv;
    }
    return true;
}

///////////////////////////////////////////

void doubleLinkedList::print()
{
    for (Node *cur = head; cur; cur = cur->next)
    {
        cout << cur->data << " ";
    }
    cout << "\n";
}

void test()
{
    doubleLinkedList list;
    list.insert_sorted(1);
    list.insert_sorted(5);
    list.insert_sorted(3);
    list.insert_sorted(10);
    list.insert_sorted(5);

    list.print();
}
//////////////////////////////////////////
int main()
{
    test();
}
