# LeetCode 2780 - Minimum Index of a Valid Split
## Problem
An element `x` of an array is **dominant** if it occurs more than half the length of the array.

You are given a 0-indexed integer array `nums` having a dominant element.
Split the array at index `i` into two parts: `nums[0..i]` and `nums[i+1..n-1]`.
A split is **valid** if both parts have the same dominant element `x`.

Return the **minimum** index of a valid split, or `-1` if there is no valid split.

## Example
Input:
[1,2,2,2]
Output:
2
Explanation:
Split at index 2: [1,2,2] and [2]. Both parts have 2 as the dominant element.

## Approach
1. Find the dominant element `maxi` and its frequency `freq` using a hash map.
2. Build a prefix count array `v` where `v[i]` = number of occurrences of `maxi` in `nums[0..i]`.
3. For every split index `i`, check:
   - Left part dominant: `v[i] > (i+1)/2`
   - Right part dominant: `freq - v[i] > (n-i-1)/2`
4. Return the first (minimum) index satisfying both; else `-1`.

## Complexity
Time Complexity: O(n)
Space Complexity: O(n)

## Topics
- Array
- Hash Table
- Sorting
- Counting

## LeetCode
Problem 2780 - Minimum Index of a Valid Split
