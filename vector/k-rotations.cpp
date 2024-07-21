// A Method to make a left rotation k times, with O(N) complexity
void rotate(vector<int> &nums, int k)
{
    // Left Rotation
    int rot = k % (int)nums.size();
    int arr[nums.size() - k];
    for (int i = 0; i < k; i++)
        arr[i] = nums[i];
    for (int i = rot; i < (int)nums.size(); i++)
    {
        nums[i - rot] = nums[i];
    }

    for (int i = (nums.size() - rot); i < nums.size(); i++)
    {
        nums[i] = arr[i - (nums.size() - rot)];
    }

    for (auto i : nums)
        cout << i << " ";
}

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
