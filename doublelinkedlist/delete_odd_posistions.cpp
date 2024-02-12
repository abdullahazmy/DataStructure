#include <bits/stdc++.h>
#define ll long long
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
class Vector
{
private:
    int *arr{nullptr};
    int size{0};    // user size
    int capacity{}; // actual size
    void expand_capacity()
    {
        // Double the actual array size
        capacity *= 2;
        cout << "Expand capacity to "
             << capacity << "\n";
        int *arr2 = new int[capacity]{};
        for (int i = 0; i < size; ++i)
            arr2[i] = arr[i]; // copy data

        swap(arr, arr2);
        delete[] arr2;
    }

public:
    Vector(int size) : size(size)
    {
        if (size < 0)
            size = 1;
        capacity = size + 10;
        arr = new int[capacity]{};
    }
    ~Vector()
    {
        delete[] arr;
        arr = nullptr;
    }
    int get_size()
    {
        return size;
    }
    int get(int idx)
    {
        assert(0 <= idx && idx < size);
        return arr[idx];
    }
    void set(int idx, int val)
    {
        assert(0 <= idx && idx < size);
        arr[idx] = val;
    }
    void print()
    {
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }
    int find(int value)
    {
        for (int i = 0; i < size; ++i)
            if (arr[i] == value)
                return i;
        return -1; // -1 for NOT found
    }
    int get_front()
    {
        return arr[0];
    }
    int get_back()
    {
        return arr[size - 1];
    }
    void push_back(int value)
    {
        if (size == capacity)
            expand_capacity();
        arr[size++] = value;
    }
    void insert(int idx, int value)
    {
        assert(0 <= idx && idx < size);

        if (size == capacity)
            expand_capacity();

        // Shift all the data to right first
        for (int p = size - 1; p >= idx; --p)
            arr[p + 1] = arr[p];

        arr[idx] = value;
        ++size;
    }
    void right_rotate()
    {
        if (size <= 1)
            return;
        int end = arr[size - 1];
        for (int i = size - 1; i >= 1; --i) // 0 1 2 3 4
            arr[i] = arr[i - 1];            // 4 0 1 2 3
        arr[0] = end;
    }
    void right_rotate(int times)
    {
        if (size <= 1)
            return;
        times = times % size;
        while (times--)
        {
            right_rotate();
        }
    }
    void left_rotate()
    {
        if (size <= 1)
            return;
        int start = arr[0];
        for (int i = 0; i < size - 1; ++i) // 0 1 2 3 4
            arr[i] = arr[i + 1];           // 1 2 3 4 0
        arr[size - 1] = start;
    }
    void left_rotate(int times)
    {
        if (size <= 1)
            return;
        times = times % size;
        while (times--)
        {
            left_rotate();
        }
    }
    int pop(int idx)
    {
        assert(0 <= idx && idx < size);
        int val = arr[idx];
        for (int i = idx; i < size - 1; i++)
            arr[i] = arr[i + 1];
        --size;
        return val;
    }
    int find_transposition(int value)
    {
        int idx = find(value);
        if (idx == -1)
            return -1;
        if (idx == 0)
            return 0;
        swap(arr[idx], arr[idx - 1]);
        return idx - 1;
    }
};
struct Node
{
    int data{};
    Node *next{};
    Node *prev{}; // Previous node!

    Node(int data) : data(data) {}

    void set(Node *next, Node *prev)
    {
        this->next = next;
        this->prev = prev;
    }

    ~Node()
    {
        cout << "Destroy value: " << data << " at address " << this << "\n";
    }
};

class LinkedList
{
private:
    Node *head{};
    Node *tail{};
    int length = 0;

    // let's maintain how many nodes

    vector<Node *> debug_data; // add/remove nodes you use

    void debug_add_node(Node *node)
    {
        debug_data.push_back(node);
    }
    void debug_remove_node(Node *node)
    {
        auto it = std::find(debug_data.begin(), debug_data.end(), node);
        if (it == debug_data.end())
            cout << "Node does not exist\n";
        else
            debug_data.erase(it);
    }

public:
    // Below 2 deletes prevent copy and assign to avoid this mistake
    LinkedList() {}
    LinkedList(const LinkedList &) = delete;
    LinkedList &operator=(const LinkedList &another) = delete;

    void debug_print_address()
    {
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur << "," << cur->data << "\t";
        cout << "\n";
    }
    void debug_print_node(Node *node, bool is_seperate = false)
    {
        if (is_seperate)
            cout << "Sep: ";
        if (node == nullptr)
        {
            cout << "nullptr\n";
            return;
        }

        if (node->prev == nullptr)
            cout << "X\t";
        else
            cout << node->prev->data << "\t";

        cout << " <= [" << node->data << "]\t => \t";

        if (node->next == nullptr)
            cout << "X\t";
        else
            cout << node->next->data << "\t";

        if (node == head)
            cout << "head\n";
        else if (node == tail)
            cout << "tail\n";
        else
            cout << "\n";
    }
    void debug_print_list(string msg = "")
    {
        if (msg != "")
            cout << msg << "\n";
        for (int i = 0; i < (int)debug_data.size(); ++i)
            debug_print_node(debug_data[i]);
        cout << "************\n"
             << flush;
    }
    string debug_to_string()
    {
        if (length == 0)
            return "";
        ostringstream oss;
        for (Node *cur = head; cur; cur = cur->next)
        {
            oss << cur->data;
            if (cur->next)
                oss << " ";
        }
        return oss.str();
    }
    void debug_verify_data_integrity()
    {
        if (length == 0)
        {
            assert(head == nullptr);
            assert(tail == nullptr);
        }
        else
        {
            assert(head != nullptr);
            assert(tail != nullptr);
            if (length == 1)
                assert(head == tail);
            else
                assert(head != tail);
            assert(!head->prev);
            assert(!tail->next);
        }
        int len = 0;
        for (Node *cur = head; cur; cur = cur->next, len++)
        {
            if (len == length - 1) // make sure we end at tail
                assert(cur == tail);
        }

        assert(length == len);
        assert(length == (int)debug_data.size());

        len = 0;
        for (Node *cur = tail; cur; cur = cur->prev, len++)
        {
            if (len == length - 1) // make sure we end at head
                assert(cur == head);
        }
        cout << "\n";
    }
    ////////////////////////////////////////////////////////////
    // These 2 simple functions just to not forget changing the vector and length
    void delete_node(Node *node)
    {
        debug_remove_node(node);
        --length;
        delete node;
    }
    void add_node(Node *node)
    {
        debug_add_node(node);
        ++length;
    }
    void print()
    {
        for (Node *cur = head; cur; cur = cur->next)
            cout << cur->data << " ";
        cout << "\n";
    }
    void print_reversed()
    {
        for (Node *cur = tail; cur; cur = cur->prev)
            cout << cur->data << " ";
        cout << "\n";
    }

    void link(Node *first, Node *second)
    {
        if (first)
            first->next = second;
        if (second)
            second->prev = first;
    }
    void insert_end(int value)
    {
        Node *item = new Node(value);
        add_node(item);

        if (!head)
        {
            head = tail = item;
        }
        else
        {
            link(tail, item);
            tail = item;
        }
        debug_verify_data_integrity();
    }
    void insert_front(int value)
    {
        Node *item = new Node(value);
        add_node(item);

        if (!head)
            head = tail = item;
        else
        {
            link(item, head);
            head = item;
        }
        debug_verify_data_integrity();
    }
    void insert_sorted(int value)
    {
        if (!length || value <= head->data)
            insert_front(value);
        else if (value >= tail->data)
            insert_end(value);
        else
        {
            for (Node *cur = head; cur; cur = cur->next)
            {
                if (value <= cur->data)
                {
                    embed_after(cur->prev, value);
                    break;
                }
            }
        }
        debug_verify_data_integrity();
    }
    void embed_after(Node *node_before, int value)
    { // Add a node with value between node and its next
        Node *middle = new Node(value);
        add_node(middle);
        Node *node_after = node_before->next;
        link(node_before, middle);
        link(middle, node_after);
    }

    void delete_front()
    {
        if (!length)
            return;
        else if (length == 1)
        {
            delete_node(head);
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            delete_node(head->prev);
            head->prev = nullptr;
        }
        debug_verify_data_integrity();
    }
    void delete_end()
    {
        if (!length)
            return;
        else if (length == 1)
        {
            delete_node(tail);
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            delete_node(tail->next);
            tail->next = nullptr;
        }
        debug_verify_data_integrity();
    }
    Node *delete_and_link(Node *cur)
    {
        Node *prv = cur->prev;
        link(cur->prev, cur->next);
        delete_node(cur);
        return prv;
    }

    void delete_node_with_key(int value)
    {
        if (!length)
            return;
        if (head->data == value)
            delete_front();
        else
        {
            for (Node *cur = head; cur; cur = cur->next)
            {
                if (value == cur->data)
                {
                    cur = delete_and_link(cur);
                    if (!cur->next) // we removed last node!
                        tail = cur;
                }
            }
        }
        debug_verify_data_integrity();
    }

    void delete_all_nodes_with_key(int value)
    {
        if (!length)
            return;
        insert_front(value - 1); // dummy
        for (Node *cur = head->next; cur;)
        {
            if (cur->data == value)
            {
                cur = delete_and_link(cur);
                if (!cur->next)
                    tail = cur;
            }
            else
                cur = cur->next;
        }
        delete_front();

        debug_verify_data_integrity();
    }

    void delete_even_positions()
    {
        if (length <= 1)
            return;
        // cur is always odd and ->next is even
        for (Node *cur = head; cur && cur->next; cur = cur->next)
        {
            delete_and_link(cur->next);
            if (!cur->next)
                tail = cur; // in even length, the tail will change
        }
        debug_verify_data_integrity();
    }
    void delete_odd_positions()
    {
        // let's make odd positions even! Reuse old code :)
        insert_front(-1); // dummy node
        delete_even_positions();
        delete_front();
    }
};
void test0()
{
    cout << "\n\ntest0\n";
    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.delete_odd_positions();
    // some actions
    list.print();

    string expected = "2";
    string result = list.debug_to_string();
    if (expected != result)
    {
        cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
        assert(false);
    }
    list.debug_print_list("********");
}

void test1()
{
    cout << "\n\ntest1\n";
    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.delete_odd_positions();
    // some actions
    list.print();

    string expected = "2 4";
    string result = list.debug_to_string();
    if (expected != result)
    {
        cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
        assert(false);
    }
    list.debug_print_list("********");
}

void test2()
{
    cout << "\n\ntest2\n";
    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.insert_end(3);
    list.insert_end(4);
    list.insert_end(5);
    list.insert_end(6);
    list.delete_odd_positions();
    // some actions
    list.print();

    string expected = "2 4 6";
    string result = list.debug_to_string();
    if (expected != result)
    {
        cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
        assert(false);
    }
    list.debug_print_list("********");
}

void test3()
{
    cout << "\n\ntest3\n";
    LinkedList list;

    list.insert_end(1);
    list.insert_end(2);
    list.delete_odd_positions();
    list.print();

    string expected = "2";
    string result = list.debug_to_string();
    if (expected != result)
    {
        cout << "no match:\nExpected: " << expected << "\nResult  : " << result << "\n";
        assert(false);
    }
    list.debug_print_list("********");
}

int main()
{
    test0();
    test1();
    test2();
    test3();

    // must see it, otherwise RTE
    cout << "\n\nNO RTE\n";

    return 0;
}
