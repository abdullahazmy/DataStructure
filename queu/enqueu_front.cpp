#include <iostream>
using namespace std;

/*
    ! A method is added which is called prv => helps us to get the prv index of rear
       and if the rear is at the end of the array, then it's prv should be index 0
*/

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

    int prv(int val)
    {
        return (val - 1) % size;
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

    void enqueu_front(int val)
    {
        if (is_full())
            return;
        front = rear;
        enqueu(val);
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

    int dequeu_rear()
    {
        if (is_empty())
            return -1;
        added_elements--;
        int val{};
        if (rear == 0)
            val = arr[0];
        else
        {
            val = arr[rear - 1];
        }
        rear = prv(rear);
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
    queue q(4);
    q.enqueu(1);
    q.enqueu(2);
    q.enqueu(3);
    q.enqueu_front(-9);
    q.dequeu_rear();

    q.display();
}
