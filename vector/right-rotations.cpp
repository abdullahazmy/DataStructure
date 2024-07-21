#include <bits/stdc++.h>
using namespace std;

void right_rotate(vector<int> &nums, int k)
{
    // Right Rotation
    int n = k % nums.size();
    int arr[n];

    // Saving elements
    for (int i = 0; i < n; i++)
        arr[i] = nums[nums.size() - n + i];

    // The Rotation
    for (int i = nums.size() - 1; i >= n; i--)
    {
        nums[i] = nums[i - n];
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = arr[i];
    }

    for (auto i : nums)
        cout << i << " ";
}

int main() {}
