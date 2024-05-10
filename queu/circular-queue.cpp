#include <iostream>
using namespace std;

class Queue
{
private:
    int front{};
    int rear{};
    int size{};
    int *arr{};
    int added_elements{};

public:
    Queue(int size) : size(size) { arr = new int[size]; }
    bool is_full() { return added_elements == size; }
    bool is_empty() { return added_elements == 0; }

    int next(int val) { return (val + 1) % size; }

    void push(int val)
    {
        if (is_full())
            return;
        arr[rear] = val;
        added_elements++;
        rear = next(rear);
    }

    int del()
    {
        if (is_empty())
            return -1;
        added_elements--;
        return arr[front++];
    }

    void print()
    {
        for (int cur = front, steps = 0; steps < added_elements; cur = next(cur), steps++)
        {
            cout << arr[cur] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.del();
    q.del();
    q.del();
    q.push(1);
    q.push(2);
    q.push(3);

    q.print();
}
