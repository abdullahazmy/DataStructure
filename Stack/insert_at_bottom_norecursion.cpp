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
        assert(!is_full());
        if (is_empty())
        {
            insert(val);
        }
        // Right Shifting
        for (int i = top; i >= 0; i--)
        {
            arr[i + 1] = arr[i];
        }
        top++;
        arr[0] = val;
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
    stk.insert_at_bottom(8);
    stk.print(); // 3 2 1 8
}
