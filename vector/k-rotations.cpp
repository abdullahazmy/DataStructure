#include <bits/stdc++.h>
using namespace std;

// A Method to make a left rotation k times, with O(N) complexity
void rotate(vector<int> &nums, int k)
{
    // Left Rotation
    int rot = k % (int)nums.size();
    int arr[nums.size() - k];
    for (int i = 0; i < k; i++)
        arr[i] = nums[i];


    // The left Rotation
    for (int i = rot; i < (int)nums.size(); i++)
    {
        nums[i - rot] = nums[i];
    }

    // Return overiden values
    for (int i = (nums.size() - rot); i < nums.size(); i++)
    {
        nums[i] = arr[i - (nums.size() - rot)];
    }

    for (auto i : nums)
        cout << i << " ";
}

int main() {}
