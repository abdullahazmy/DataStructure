class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
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
