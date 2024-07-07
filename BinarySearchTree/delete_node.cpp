TreeNode *min_node(TreeNode *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

TreeNode *del_node(TreeNode *root, int key)
{
    if (!root)
        return root;

    if (key < root->val)
        root->left = del_node(root->left, key);
    else if (key > root->val)
        root->right = del_node(root->right, key);
    else
    {
        if (!root->left)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        TreeNode *temp = min_node(root->right);
        root->val = temp->val;
        root->right = del_node(root->right, temp->val);
    }
    return root;
}
