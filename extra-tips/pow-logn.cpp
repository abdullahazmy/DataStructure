// A method to calculate power with complexity of log(n)

void solve(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b % 2 == 1)
            res *= a;
        a *= a;
        b /= 2;
    }

    cout << res;
}
