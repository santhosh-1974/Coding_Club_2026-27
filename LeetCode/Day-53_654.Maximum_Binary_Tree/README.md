# LeetCode 654 - Maximum Binary Tree
## Problem
Given an integer array `nums` with no duplicates, build a **maximum binary tree** recursively:

1. Create a root node whose value is the maximum value in `nums`.
2. Recursively build the left subtree from the prefix to the left of the maximum.
3. Recursively build the right subtree from the suffix to the right of the maximum.

Return the root of the constructed tree.

## Example
Input:
nums = [3,2,1,6,0,5]
Output:
[6,3,5,null,2,0,null,null,1]
Explanation: 6 is the global max → root. Left part [3,2,1] builds the left subtree with 3 on top; right part [0,5] builds the right subtree with 5 on top.

Input:
nums = [3,2,1]
Output:
[3,null,2,null,1]

## Approach
Divide and conquer on index ranges (no subarray copies):

1. `construct(nums, st, end)` returns `nullptr` for an empty range (`st > end`).
2. Find the index of the maximum element in `[st, end]` with a linear scan (`find_max`).
3. Make that element the root, then recursively build the left subtree on `[st, index-1]` and the right subtree on `[index+1, end]`.

Since all values are unique, the maximum index is unambiguous, so the tree is uniquely determined.

## Complexity
Time Complexity: O(n²) worst case (sorted input makes every range shrink by one and rescans for the max); average/balanced case O(n log n).
Space Complexity: O(n) for the tree, plus O(h) recursion stack (h = tree height, O(n) worst case).

## Topics
- Array
- Divide and Conquer
- Stack
- Tree
- Monotonic Stack

## LeetCode
Problem 654 - Maximum Binary Tree
