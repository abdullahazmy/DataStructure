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
    void del(int idx);
};
void singleLinkedList::insert(int val)
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
}

void singleLinkedList::print()
{
    for (Node *cur = head; cur; cur = cur->next)
    {
        cout << cur->data << " ";
    }
    cout << "\n";
}
int main()
{
    singleLinkedList list1;
    list1.insert(5);
    list1.insert(10);
    list1.insert(30);
    list1.print();
}
