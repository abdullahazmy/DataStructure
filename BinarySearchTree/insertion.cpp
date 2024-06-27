void _insert(TreeNode *&root, int target)
{
    if (!root)
    {
        root = new TreeNode(target); // Create a new node if root is null
        return;
    }

    if (target < root->val)
    {
        if (!root->left)
            root->left = new TreeNode(target); // Insert the new node as the left child
        else
            _insert(root->left, target); // Recurse to the left subtree
    }
    else if (target > root->val)
    {
        if (!root->right)
            root->right = new TreeNode(target); // Insert the new node as the right child
        else
            _insert(root->right, target); // Recurse to the right subtree
    }
}
