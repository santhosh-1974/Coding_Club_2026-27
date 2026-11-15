# LeetCode 4111 - Count Consistent Subarrays I
## Problem
Given an integer array `nums`, a subarray is called **consistent** if the bitwise AND of all its elements equals the minimum value of the subarray. Return the number of consistent subarrays in `nums`.

## Example
Input:
nums = [5,3,1,2]
Output:
6
Explanation: All four single elements, [3,1] (3 AND 1 = 1, min = 1), and [5,3,1] (5 AND 3 AND 1 = 1, min = 1).

Input:
nums = [1,1,1]
Output:
6
Explanation: Every subarray's AND and minimum are both 1.

Input:
nums = [0]
Output:
1

## Approach
Brute-force extension over all subarrays with two running values:

1. Fix the left endpoint `i` of the subarray.
2. Extend the right endpoint `j` from `i` to the end, maintaining incrementally:
   - `mini` — the minimum of the subarray seen so far,
   - `val` — the running bitwise AND of all elements seen so far.
3. After absorbing `nums[j]`, if `mini == val`, this subarray is consistent — increment the answer.

Because AND can only turn bits off as the window grows, maintaining both aggregates incrementally keeps each extension step O(1). Every subarray `[i..j]` is examined exactly once.

## Complexity
Time Complexity: O(n²) — for each of the n left endpoints, extend right with constant work per step.
Space Complexity: O(1) — only a few scalar variables.

## Topics
- Array
- Bit Manipulation
- Brute Force

## LeetCode
Problem 4111 - Count Consistent Subarrays I
