#include <iostream>
using namespace std;
struct Node
{
    int data{};
    Node *next{};
    Node(int data) : data(data) {}
};

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

    void embed_after(Node *node, int value)
    {
        // Add a node with value between node and its next
        Node *item = new Node(value);
        ++length;

        item->next = node->next;
        node->next = item;
    }

    Node *get_prv(Node *node)
    {
        for (Node *cur = head, *prv = nullptr; cur; prv = cur, cur = cur->next)
        {
            if (cur == node)
                return prv;
        }
        return nullptr;
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
    void deletenxt(Node *node);
    void delete_evenpos();
    void insert_and_link(Node *node);
    void insert_sorted(int val);
    void swap_ht();
    void left_rotate(int k);
    void remove_duplicates();
    void remove_last_occurenceK(int k);
    Node *move_end(Node *cur, Node *prv);
    void move_back_last_occurence(int k); //* To move all nodes with that key to the end of the list
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
    int ctr = 1;
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

void linkedlist::deletenxt(Node *node)
{
    if (node->next == tail)
        delete_tail();
    else
    {
        Node *tmp = node->next;
        node->next = node->next->next;
        delete_node(tmp);
    }
    bool is_tail = node->next == nullptr;
    if (is_tail)
    {
        tail = node;
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

void linkedlist::insert_sorted(int val)
{
    Node *item = new Node(val);
    if (!head || head->data >= val)
    {
        insert_front(val); // If list is empty or new node should be inserted at the front
        return;
    }

    Node *cur = head;
    while (cur->next && cur->next->data < val)
    {
        cur = cur->next; // Move to the node whose next node's data is greater than val
    }

    // Now, cur points to the node before the insertion point
    item->next = cur->next;
    cur->next = item;
    length++;
}

// 2nd Node   --- getnth(n-1);

void linkedlist::swap_ht()
{
    if (length <= 1)
        return;
    if (!head->next->next)
    {
        tail->next = head;
        head->next = nullptr;
        swap(head, tail);
        return;
    }

    Node *cur = head;
    // Node *last = get_backnth(length - 1);
    Node *last = get_prv(tail);
    tail->next = cur->next;
    last->next = cur;
    cur->next = nullptr;
    Node *tmp = head;
    head = tail;
    tail = tmp;
    // swap(head, tail);
    check();
}

// K is tail
// After K is head

void linkedlist::left_rotate(int k)
{
    if (length <= 1 || k % length == 0)
        return;
    else
        k %= length;
    Node *t = get_backnth(k);
    tail->next = head;
    tail = t;
    head = t->next;
    tail->next = nullptr;
}

/// @brief
void linkedlist::remove_duplicates()
{
    if (length <= 1)
        return;
    for (Node *cur = head; cur; cur = cur->next)
    {
        for (Node *cor = cur->next, *prv = cur; cor;)
        {
            if (cur->data == cor->data)
            {
                deletenxt(prv);
                cor = prv->next;
            }
            else
            {
                prv = cor, cor = cor->next;
            }
        }
    }
}

void linkedlist::remove_last_occurenceK(int k)
{
    Node *tmp = nullptr, *prv = nullptr, *prev = nullptr;
    for (Node *cur = head; cur; prv = cur, cur = cur->next)
    {
        if (cur->data == k)
        {
            tmp = cur;
            prev = prv;
        }
    }

    if (!tmp)
        return;
    if (tmp == head)
        delete_front();
    else if (tmp == tail)
        delete_tail();
    else
    {
        deletenxt(prev);
    }
}

Node *linkedlist::move_end(Node *cur, Node *prv)
{
    // if (length <= 1)
    //     return cur;
    if (cur == tail)
        return cur;
    Node *nxt = cur->next;
    tail->next = cur;

    if (prv)
        prv->next = nxt;
    else
        head = nxt;
    tail = cur;
    tail->next = nullptr;
    return nxt;
}

void linkedlist::move_back_last_occurence(int k)
{
    if (length <= 1)
        return;
    int len = length;
    for (Node *cur = head, *prv = nullptr; len--;)
    {
        if (cur->data == k)
            cur = move_end(cur, prv);
        else
        {
            prv = cur;
            cur = cur->next;
        }
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
    ll.insert_end(1);
    ll.insert_end(2);
    ll.insert_end(3);
    ll.insert_end(2);
    ll.insert_end(4);
    ll.insert_end(1);
    ll.move_back_last_occurence(1);
    ll.print();
}
