vector<int> solution(vector<int> &A, int k)
{
    if (k == 0)
        return A;
    vector<int> ans(A.size());
    k %= A.size();
    for (int i = 0; i < A.size(); i++)
    {
        ans[i] = A[(i + k) % A.size()];
    }

    return ans;
}
