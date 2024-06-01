#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct TreeNode
{
    int val{};
    TreeNode *right{};
    TreeNode *left{};
    TreeNode(int data) : val(data) {}
};

class BinaryTree
{
private:
    TreeNode *root{};

public:
    BinaryTree(int data) : root(new TreeNode(data)) {}

    void add(vector<int> value, vector<char> direction)
    {
        TreeNode *cur = root;
        for (int i = 0; i < (int)value.size(); i++)
        {
            if (direction[i] == 'R')
            {
                if (!cur->right)
                    cur->right = new TreeNode(value[i]);
                else
                    assert(cur->right->val == value[i]);
                cur = cur->right;
            }

            else
            {
                if (!cur->left)
                    cur->left = new TreeNode(value[i]);
                else
                    assert(cur->left->val == value[i]);
                cur = cur->left;
            }
        }
    }

    void _print_inorder(TreeNode *cur)
    {
        if (!cur)
            return;
        _print_inorder(cur->left);
        cout << cur->val << " ";
        _print_inorder(cur->right);
    }

    void print_inorder()
    {
        _print_inorder(root);
    }
};

int main()
{
    BinaryTree tree(1);
    tree.add({2, 4, 7}, {'L', 'L', 'L'});
    tree.add({2, 4, 8}, {'L', 'L', 'R'});
    tree.add({2, 5, 9}, {'L', 'R', 'R'});
    tree.add({3, 6, 10}, {'R', 'R', 'L'});
    tree.print_inorder();
}
