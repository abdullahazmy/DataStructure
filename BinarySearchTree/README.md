### Binary Search Tree (BST)

Time complexity for searching for an element inside the BST is o(h) where h is the height of the tree --- is same with o(logn) in case the tree is balanced, as if tree is balanced it's height is o(logn).

Inorder Traversal is always sorted for BST

---

Successor in a BST is the first element after you in sorted order (Inorder Traversal)
which means, the smallest node at your right subtrees.
If the node has no right node, and you want to get it's successor, then return the root of the whole chain.
The largest value in the tree has no successor

---

Predecessor is the number before you in the sorted array, the vice versa of Successor.
