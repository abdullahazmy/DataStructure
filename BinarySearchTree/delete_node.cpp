TreeNode *min_node(TreeNode *root)
{
    while (root && root->left)
        root = root->left;
    return root;
}

// Function to delete a node with a given key from the binary search tree
TreeNode *del_node(TreeNode *root, int key)
{
    // If the root is null, return null
    if (!root)
        return root;

    // If the key is less than the root value, recursively delete the key from the left subtree
    if (key < root->val)
        root->left = del_node(root->left, key);
    // If the key is greater than the root value, recursively delete the key from the right subtree
    else if (key > root->val)
        root->right = del_node(root->right, key);
    // If the key is equal to the root value, perform the deletion
    else
    {
        // If the root has no left child, replace the root with its right child
        if (!root->left)
        {
            TreeNode *temp = root->right;
            delete root;
            return temp;
        }
        // If the root has no right child, replace the root with its left child
        else if (!root->right)
        {
            TreeNode *temp = root->left;
            delete root;
            return temp;
        }

        // If the root has both left and right children, find the minimum value node in the right subtree
        TreeNode *temp = min_node(root->right);
        // Replace the root value with the minimum value node
        root->val = temp->val;
        // Recursively delete the minimum value node from the right subtree
        root->right = del_node(root->right, temp->val);
    }
    // Return the modified root
    return root;
}
