### Binary Tree Documentation for implemented Methods and ideas

## Most Used Types Of Binary Trees

**Full Binary Tree**

A Binary Tree is a full binary tree if every node has 0 or 2 children. The following are examples of a full binary tree. We can also say a full binary tree is a binary tree in which all nodes except leaf nodes have two children. 

**Degenerate (or pathological) tree**


Is the Binary Tree which is like the linkedlist

**Complete Binary Tree**


A Binary Tree is a Complete Binary Tree if all the levels are completely filled except possibly the last level and the last level has all keys as left as possible.

**Perfect Binary Tree**


A Binary tree is a Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same level. 

In a Perfect Binary Tree, the number of leaf nodes is the number of internal nodes plus 1   

 L = I + 1 Where L = Number of leaf nodes, I = Number of internal nodes.

--> A binary tree is balanced if the height of the tree is O(Log n) 


---

- The code of [MaxDepth](https://github.com/abdullahazmy/DataStructure/blob/main/BinaryTree/maxDepth.cpp) we made at the return + 1, to calculate the depth of the root
- The code that checks of the Tree is full or not [FBT](https://github.com/abdullahazmy/DataStructure/blob/main/BinaryTree/is_fullBT.cpp#L14) is what a binary tree is, if it's leaf then we return true, else we should check that the node have two childrens (right, and left)

-> [level-order-traversal](https://github.com/abdullahazmy/DataStructure/blob/main/BinaryTree/level_order_traversal.cpp)
> We print nodes according to the level with using a queue, so we print each level
