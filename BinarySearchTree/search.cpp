bool _search(TreeNode *root, int target)
{
    if (!root)
        return false;

    if (root->val == target)
        return true;

    if (target > root->val)
        return _search(root->right, target);

    if (target < root->val)
        return _search(root->left, target);
}
