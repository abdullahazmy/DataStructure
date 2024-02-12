#include <iostream>
using namespace std;
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
    void link(Node *first, Node *second);
    void add_node(Node *node);
    void delete_node(Node *cur);
    void delete_and_link(Node *cur);

public:
    void insert_end(int val);
    void insert_front(int val);
    void insert_sorted(int val); // By Value
    void delete_front();
    void delete_end();
    void delete_node_with_key(int key);
    void delete_all_nodes_with_key(int k);
    void print();
};

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

void doubleLinkedList::delete_and_link(Node *cur)
{
    if (!head || !length)
        return;

    if (length <= 1)
        delete_front();
    bool is_tail = (tail == cur);
    if (is_tail)
    {
        delete_end();
        return;
    }
    link(cur->prv, cur->next);
    delete_node(cur);
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

    link(item, head);
    head = item;
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

    if (length <= 1)
    {
        if (head->data == k)
            delete_front();
        return;
    }
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
            Node *tmp = cur->prv;
            delete_and_link(cur);
            cur = tmp;
        }

        else
        {
            cur = cur->next;
        }
    }
    head->prv = nullptr;
    tail->next = nullptr;
}

//////////////////////////////////////////

void doubleLinkedList::print()
{
    for (Node *cur = head; cur; cur = cur->next)
        cout << cur->data << " ";
    cout << "\n";
}
int main()
{
    doubleLinkedList ll;
    ll.insert_end(30);
    ll.insert_end(20);
    ll.insert_end(20);
    ll.insert_end(30);

    ll.delete_all_nodes_with_key(20);
    ll.print();
    cout << "azmy";
}
