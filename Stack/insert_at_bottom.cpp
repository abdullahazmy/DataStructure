#include <bits/stdc++.h>
#define ll long long
using namespace std;

// simple trick to avoid re-changing the class
typedef int type;

class Stack
{
private:
    int size{};
    int top{};
    type *array{};

public:
    Stack(int size) : size(size), top(-1)
    {
        array = new type[size];
    }

    ~Stack()
    {
        delete[] array;
    }

    void push(type x)
    {
        assert(!isFull());
        array[++top] = x;
    }

    type pop()
    {
        assert(!isEmpty());
        return array[top--];
    }

    type peek()
    {
        assert(!isEmpty());
        return array[top];
    }

    int isFull()
    {
        return top == size - 1;
    }

    int isEmpty()
    {
        return top == -1;
    }

    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << array[i] << " ";
        cout << "\n";
    }
    void display_reversed()
    {
        for (int i = 0; i <= top; i++)
            cout << array[i] << " ";
        cout << "\n";
    }

    void insert_at_bottom(int x)
    {
        if (isEmpty())
            push(x);
        else
        {
            int cur = pop();
            insert_at_bottom(x);
            push(cur);
        }
    }
};

int main()
{
    Stack stk(10);
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.display(); // 3 2 1
    stk.insert_at_bottom(8);
    stk.display(); // 3 2 1 7
}
