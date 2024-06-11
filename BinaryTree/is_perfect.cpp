 // Function to calculate the depth of the leftmost path in the tree
    int depth(Node *node)
    {
        int d = 0; // Initialize depth counter
        while (node != nullptr)
        {
            d++;               // Increment depth for each level
            node = node->left; // Move to the next level along the leftmost path
        }
        return d; // Return the total depth
    }

    // Utility function to check if the tree is perfect
    bool is_perfect_util(Node *root, int d, int level = 0)
    {
        if (root == nullptr)
            return true; // Base case: an empty tree is perfect

        if (root->left == nullptr && root->right == nullptr)
            return (d == level + 1); // Check if leaf node is at the expected depth

        if (root->left == nullptr || root->right == nullptr)
            return false; // If one child is missing, the tree is not perfect

        // Recursively check left and right subtrees
        return is_perfect_util(root->left, d, level + 1) &&
               is_perfect_util(root->right, d, level + 1);
    }

    // Main function to check if a binary tree is perfect
    bool is_perfect(Node *root)
    {
        int d = depth(root);             // Calculate the depth of the tree
        return is_perfect_util(root, d); // Use the utility function to check perfection
    }
