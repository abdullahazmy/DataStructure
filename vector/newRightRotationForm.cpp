vector<int> solution(vector<int> &A, int k)
{
    if (k == 0)
        return A;
    vector<int> ans(A.size());
    for (int i = 0; i < A.size(); i++)
    {
        ans[(i + k) % A.size()] = A[i];
    }

    return ans;
}
