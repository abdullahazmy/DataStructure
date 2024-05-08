#include <iostream>
#include <cassert>
using namespace std;

class Stack
{
private:
    int top = -1;
    int size{};
    int *arr{};

public:
    Stack(int size) : size(size) { arr = new int[size]; }
    ~Stack() { delete[] arr; }
    bool is_full() { return top == size - 1; }
    bool is_empty() { return top == -1; }
    void insert(int val) { !is_full() ? arr[++top] = val : 0; }
    int peak() { return arr[top]; }
    int pop()
    {
        if (is_empty())
            return -1;
        return arr[top--];
    }
    void insert_at_bottom(int val)
    {
        if (is_empty())
        {
            insert(val);
            return;
        }

        int temp = pop();
        insert_at_bottom(val);
        insert(temp);
    }

    void reverse()   // O(N)
    {
        int *tmp = new int[size];
        int n = top;
        for (int i = 0; i <= n; i++)
        {
            tmp[i] = pop();
        }

        for (int i = 0; i <= n; i++)
        {
            insert(tmp[i]);
        }
        delete[] tmp;
    }

    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    Stack stk(10);
    stk.insert(1);
    stk.insert(2);
    stk.insert(3);
    stk.print(); // 3 2 1
    stk.reverse();
    stk.print(); // 1 2 3
}
