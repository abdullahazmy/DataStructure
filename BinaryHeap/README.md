### What is BinaryHeap?

Is a complete binary tree, at which the smallest value is located inside the root (for min heap tree)

for (max heap tree) the max value is located at the root

#### Important notes
1. We can work with a complete Binary Tree as an array
2. To know the left child `node_idx * 2 + 1`
3. To know the right child `node_idx * 2 + 2`
4. To know the parent `(node_idx - 1) / 2`

5. We insert the root then left then right, then move to the next subtree behind you and do the same formula
  ![image](https://github.com/abdullahazmy/DataStructure/assets/125517573/ee732fbd-7d56-46ca-870d-bd6ea519c16d)


---

`priority_queue<int, vector<int>, greater<int>> q;` this is used to sort in ascending order
while the normal priority_queue sorts in descending order

-  The top element at normal priority_queue is the max element
-  At the mentioned one, it's the smallest element
-  kth_smallest => use max_heap
-  kth_largest => use min_heap
