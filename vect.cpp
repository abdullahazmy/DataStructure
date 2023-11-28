#include <iostream>
#include <cassert>
using namespace std;

class vector
{
private:
    int *arr = nullptr;
    int size = 0;
    int capacity = 0;
    void expand_capacity()
    {
        capacity *= 2;
        int *arr2 = new int[capacity];
        for (int i = 0; i < size; ++i)
        {
            arr2[i] = arr[i];
        }

        swap(arr, arr2);
        delete[] arr2;
    }

public:
    vector(int size) : size(size)
    {
        if (size < 0)
            size = 1;
        capacity = size + 10;
        arr = new int[capacity];
    }

    ~vector()
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

    int get_front()
    {
        return arr[0];
    }

    int get_back()
    {
        return arr[size - 1];
    }

    int find(int value)
    {
        for (int i = 0; i < size; ++i)
            if (arr[i] == value)
                return i;
        return -1;
    }

    void push_back(int val)
    {
        if (size == capacity)
            expand_capacity();
        arr[size++] = val;
    }

    void insert(int idx, int val)
    {
        assert(0 <= idx && idx <= size);
        if (size == capacity)
            expand_capacity();
        for (int i = size - 1; i >= idx; --i)
            arr[i + 1] = arr[i];

        arr[idx] = val;
        ++size;
    }

    void right_rotate()
    {
        int l = arr[size - 1];
        for (int p = size - 2; p >= 0; --p)
            arr[p + 1] = arr[p];
        arr[0] = l;
    }

    void left_rotate()
    {
        int r = arr[0];
        for (int i = 1; i <= size; ++i)
        {
            arr[i - 1] = arr[i];
        }

        arr[size - 1] = r;
    }

    void right_rotation2(int time)
    {
        time %= size;
        while (time--)
        {
            right_rotate();
        }
    }

    int pop(int idx)
    {
        int val = arr[idx];
        for (int p = idx; p <= size - 1; ++p)
        {
            arr[p] = arr[p + 1];
        }
        size--;
        return val;
    }

    int find_transposition(int val)
    {
        int idx = find(val);
        if (idx == 0)
            return 0;
        int x = arr[idx - 1];
        arr[idx - 1] = arr[idx];
        arr[idx] = x;
        return idx - 1;
    }
};
int main()
{
    int n = 5;
    vector v(n);
    for (int i = 0; i < n; ++i)
        v.set(i, i);
    v.print();
    cout << v.find_transposition(30) << "\n";
    v.print();
    cout << v.find_transposition(30) << "\n";
    v.print();
}