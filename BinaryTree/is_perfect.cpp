bool _is_perfectBT(TreeNode *root, int h) {
    if (!root)
        return h == 0;
    return _is_perfectBT(root->left, h - 1) && _is_perfectBT(root->right, h - 1);
}

bool is_perfect(TreeNode *root) {
    if (!root)
        return true;
    int h = height(root);
    return _is_perfectBT(root, h);
}

// The time complexity here is o(n+n) ---> o(n)
