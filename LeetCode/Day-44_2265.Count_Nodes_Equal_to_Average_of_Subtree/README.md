# LeetCode 2265 - Count Nodes Equal to Average of Subtree
## Problem
Given the root of a binary tree, return the number of nodes where the value of the node is equal to the **average** of the values in its subtree (inclusive of itself).

The average of `n` nodes is the sum of the values divided by `n`, rounded down (integer division).

## Example
Input:
[4,8,5,0,1,null,6]
Output:
5
Explanation:
- Node 0, 1 and 6 have average equal to their value (single node subtrees).
- Node 5's subtree average = 5.
- Node 4's subtree average = (4 + 8 + 5 + 0 + 1 + 6) / 6 = 4.
Total = 5.

## Approach
Use a post-order DFS traversal. For each node, compute the **sum** and **count** of nodes in its subtree by combining the results of the left and right children:

1. Recursively get `(sum, count)` from the left and right subtrees.
2. Compute the current subtree's `sum = ls.sum + rs.sum + root->val` and `count = ls.count + rs.count + 1`.
3. The average is `sum / count` (integer division), which equals the floor for non-negative values.
4. If the average equals `root->val`, increment a counter (passed by reference).
5. Return the `(sum, count)` pair up to the parent.

## Complexity
Time Complexity: O(n) — each node is visited once.
Space Complexity: O(h) — recursion stack, where h is the tree height.

## Topics
- Tree
- Depth-First Search
- Binary Tree

## LeetCode
Problem 2265 - Count Nodes Equal to Average of Subtree
