class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 0; i < k; i++)
            q.emplace(nums[i]);
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] > q.top())
            {
                q.pop();
                q.emplace(nums[i]);
            }
        }
        return q.top();
    }
};

// leetcode 215
