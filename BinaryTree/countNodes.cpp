#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val{};
    Node *left{};
    Node *right{};
    Node(int val) : val(val) {}
};

struct BinaryTree
{
    Node *root{};
    BinaryTree(int data) { root = new Node(data); }

    void insert(vector<int> data, vector<char> directions)
    {
        Node *curr = root;
        for (int i = 0; i < data.size(); i++)
        {
            if (directions[i] == 'R')
            {
                if (!curr->right)
                    curr->right = new Node(data[i]);
                else
                    assert(curr->right->val == data[i]);
                curr = curr->right;
            }

            else
            {
                if (!curr->left)
                    curr->left = new Node(data[i]);
                else
                    assert(curr->left->val == data[i]);
                curr = curr->left;
            }
        }
    }

    void _inorder_print(Node *node)
    {
        if (!node)
            return;
        _inorder_print(node->left);
        cout << node->val << " ";
        _inorder_print(node->right);
    }

    void print_inorder()
    {
        _inorder_print(root);
        cout << "\n";
    }
};

class Solution
{
public:
    int Max(Node *root)
    {
        if (!root)
            return INT_MIN;
        int mxleft = Max(root->left);
        int mxright = Max(root->right);
        return max({mxleft, mxright, root->val});
    }

    int fsum(Node *root)
    {
        if (!root)
            return 0;
        return (root->val + fsum(root->left) + fsum(root->right));
    }

    bool is_leaf(Node *root) { return root && !root->left && !root->right; }

    bool is_full_BT(Node *root)
    {
        if (!root)
            return false;
        if (is_leaf(root))
            return true;
        if (root->left && root->right)
        {
            return (is_full_BT(root->left) && is_full_BT(root->right));
        }

        return false;
    }

    bool is_perfect(Node *root, int h)
    {
        if (is_leaf(root))
            return h == 0; // All leaves must be on the same last level

        if (!root->left && root->right || root->left && !root->right)
            return false; // one child!

        // perfect on level h is perfect on h-1 for children
        return is_perfect(root->left, h - 1) && is_perfect(root->right, h - 1);
    }

    int countNodes(Node *root)
    {
        if (!root)
            return 0;
        return countNodes(root->left) + countNodes(root->right) + 1; // +1 is because of the root number
    }
};

int main()
{
    BinaryTree tree(1);
}
