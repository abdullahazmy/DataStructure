bool is_leaf(TreeNode *root) { return root && !root->left && !root->right; }

int min(TreeNode *root)
{
    if (is_leaf(root) || !root->left)
        return root->val;
    if (root->left)
        return min(root->left);
}


// We checked the condition of !root->left, as it maybe a linkedlist and the min val is root itself and it has nodes on the right
