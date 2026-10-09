# 2294. Partition Array Such That Maximum Difference Is K

## Question

Given an integer array `nums` and an integer `k`, partition `nums` into one or more groups such that the difference between the largest and smallest elements in each group is at most `k`. Return the minimum number of groups needed.

## Examples

### Example 1

Input: `nums = [3,6,1,2,5]`, `k = 2`

Output: `2`

Explanation: One valid partition is `[1,2,3]` and `[5,6]`.

### Example 2

Input: `nums = [1,2,3]`, `k = 1`

Output: `2`

Explanation: One valid partition is `[1,2]` and `[3]`.

### Example 3

Input: `nums = [2,2,4,5]`, `k = 0`

Output: `3`

Explanation: The groups can be `[2,2]`, `[4]`, and `[5]`.

## Constraints

- `1 <= nums.length <= 10^5`
- `0 <= nums[i] <= 10^9`
- `0 <= k <= 10^9`

## Topics

- Array
- Greedy
- Sorting

## Approach

1. Sort `nums` so each group can be formed from consecutive values.
2. Track the first value of the current group.
3. When the difference between the current value and the group's first value exceeds `k`, start a new group at the current value.
4. Return the number of groups.

## Time Complexity

`O(n log n)` for sorting the array.

## Space Complexity

`O(1)` extra space, excluding the space used internally by sorting.
