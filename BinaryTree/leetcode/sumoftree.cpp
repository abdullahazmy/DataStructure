    int fsum(Node *root)
    {
        if (!root)
            return 0;
        return (root->val + fsum(root->left) + fsum(root->right));
    }
