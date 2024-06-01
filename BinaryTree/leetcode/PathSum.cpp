// Solution for a problem
// Asking for the largest sum for a specific path in a BinaryTree

class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;

        targetSum -= root->val;
        if (is_leaf(root))
            return targetSum == 0;
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
