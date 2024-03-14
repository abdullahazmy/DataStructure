#include <iostream>
using namespace std;

class queue
{
private:
    int size{};
    int front{};
    int rear{};
    int added_elements = 0;
    int *arr{};

public:
    queue(int size) : size(size)
    {
        arr = new int[size];
    }

    int next(int val)
    {
        return (val + 1) % size;
    }

    bool is_empty() { return added_elements == 0; }
    bool is_full() { return added_elements == size; }

    void enqueu(int val)
    {
        if (is_full())
            return;
        arr[rear] = val;
        rear = next(rear);
        added_elements++;
    }

    int dequeu()
    {
        if (is_empty())
            return -1;
        int val = arr[front];
        front++;
        added_elements--;
        return val;
    }

    void display()
    {
        for (int cur = front, step = 0; step < added_elements; step++, cur = next(cur))
        {
            cout << arr[cur] << " ";
        }
        cout << "\n";
    }
};

int main()
{
    queue q(3);
    q.enqueu(1);
    q.enqueu(2);
    q.enqueu(3);
    q.dequeu();
    q.enqueu(0);
    q.display();
}
