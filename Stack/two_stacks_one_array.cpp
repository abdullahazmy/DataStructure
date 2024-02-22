#include <iostream>
#include <cassert>
using namespace std;

// simple trick to avoid re-changing the class
typedef int type;
class Stack
{
private:
    int size{};
    int top1{};
    int top2{};
    type *array{};

public:
    Stack(int size) : size(size), top1(-1), top2(size)
    {
        array = new type[size];
    }

    ~Stack()
    {
        delete[] array;
    }

    void push(int id, type x)
    {
        assert(!isFull());
        if (id == 1)
            array[++top1] = x;
        else
        {
            array[--top2] = x;
        }
    }

    type pop(int id)
    {
        assert(!isEmpty(id));
        if (id == 1)
            return array[top1--];
        return array[top2++];
    }

    type peek(int id)
    {
        assert(!isEmpty(id));
        if (id == 1)
            return array[top1];
        else
            return array[top2];
    }

    int isFull()
    {
        return top1 + 1 >= top2;
    }

    int isEmpty(int id)
    {
        if (id == 1)
            return top1 == -1;
        return top2 == size;
    }

    void display()
    {
        for (int i = top1; i >= 0; i--)
            cout << array[i] << " ";
        cout << "\n";

        for (int i = top2; i < size; i++)
            cout << array[i] << " ";
        cout << "\n";
    }
};

int main()
{
    Stack stk(10);
    stk.push(2, 5);
    stk.push(2, 6);
    stk.pop(2);
    stk.push(2, 7);
    stk.push(2, 9);

    stk.push(1, 4);
    stk.push(1, 6);
    stk.push(1, 8);
    stk.display();
    return 0;
}
