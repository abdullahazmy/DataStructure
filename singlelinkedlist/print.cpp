#include <iostream>
using namespace std;
struct Node
{
    int data{};
    Node *next;
    Node(int data) : data(data) {}
};
void print(Node *head)
{
    for (; head; head = head->next)
        cout << head->data << " ";

    cout << endl;
}
int main()
{
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    print(node1);
}