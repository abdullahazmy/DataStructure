bool is_leaf(Node *root) { 
    return root && !root->left && !root->right; 
}

bool is_full_BT(Node *root) {
    if (!root)
        return true; // An empty tree is considered a full binary tree
    if (is_leaf(root))
        return true; // A leaf node is a full binary tree

    // Check if both left and right children exist
    if (root->left && root->right) {
        // Recursively check the left and right subtrees
        return is_full_BT(root->left) && is_full_BT(root->right);
    }
    
    // If one child is NULL and the other is not, it's not a full binary tree
    return false;
}
