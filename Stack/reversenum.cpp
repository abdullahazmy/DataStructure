#include <iostream>
#include <stack>
using namespace std;

int reverse_num(int n)
{
    if (n == 0)
        return 0;
    stack<int> s;
    while (n) // 1234
    {
        s.push(n % 10), n /= 10;
    }
    int tens = 1;
    while (!s.empty())
    {
        n = s.top() * tens + n, tens *= 10;
        s.pop();
    }
    return n;
}

int main()
{
    int n;
    cin >> n;
    cout << reverse_num(n);
}
