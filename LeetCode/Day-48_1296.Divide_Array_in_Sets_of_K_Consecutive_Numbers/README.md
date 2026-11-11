# LeetCode 1296 - Divide Array in Sets of K Consecutive Numbers
## Problem
Given an array of integers `nums` and a positive integer `k`, return `true` if it is possible to divide this array into sets of `k` consecutive numbers, otherwise return `false`.

Each element of the array must be used in **exactly one** group.

## Example
Input:
nums = [1,2,3,3,4,4,5,6], k = 4
Output:
true
Explanation:
The array can be divided into [1,2,3,4] and [3,4,5,6].

Input:
nums = [3,2,1,2,3,4,3,4,5,9,10,11], k = 3
Output:
true
Explanation:
Groups are [1,2,3], [2,3,4], [3,4,5] and [9,10,11].

Input:
nums = [1,2,3,4], k = 3
Output:
false
Explanation:
There is no way to divide the array into sets of 3 consecutive numbers.

## Approach
Greedy with a frequency map (`std::map` keeps keys sorted):

1. Count the frequency of every value in `nums`.
2. Repeatedly build one group of `k` numbers by walking the map from the smallest remaining key:
   - Each next value must be exactly `previous + 1`; otherwise a gap breaks the group → return `false`.
   - Decrement its count and erase the key when the count reaches 0.
   - If the map becomes empty before `k` values are taken, the leftover group is incomplete → return `false`.
3. If every group gets built (map drains exactly after a full group), return `true`.

Using a `map` means the smallest available value is always consumed first, so no smaller sequence can be starved by a larger one.

## Complexity
Let `n = len(nums)`, and `u` = number of unique values.
Time Complexity: O(n log u) — each element decremented once; each group walk scans the ordered map.
Space Complexity: O(u) — the frequency map.

## Topics
- Array
- Hash Table
- Greedy
- Sorting

## LeetCode
Problem 1296 - Divide Array in Sets of K Consecutive Numbers
