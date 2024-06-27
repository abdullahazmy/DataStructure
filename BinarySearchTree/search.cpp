bool _search(TreeNode *root, int target)
{
    if (!root) // Base case: If the node is null, target is not found
        return false;

    if (root->val == target) // If the current node's value is the target, return true
        return true;

    if (target > root->val) // If the target is greater, search in the right subtree
        return _search(root->right, target);

    return _search(root->left, target); // Otherwise, search in the left subtree
}
