# 453. Minimum Moves to Equal Array Elements

## Question

Given an integer array `nums`, return the minimum number of moves required to make all array elements equal. In one move, you can increment `n - 1` elements by `1`.

## Example

```text
Input: nums = [1, 2, 3]
Output: 3
```

## Constraints

- `1 <= nums.length <= 10^5`
- `-10^9 <= nums[i] <= 10^9`

## Topics

- Array
- Math

## Approach

Incrementing `n - 1` elements by one has the same effect on equality as decrementing the remaining element by one. Therefore, the minimum number of moves is the sum of each value's difference from the minimum value in the array.

1. Find the minimum value in `nums`.
2. Sum `nums[i] - minimum` for every element.

## Time Complexity

`O(n)` to find the minimum and compute the sum.

## Space Complexity

`O(1)` extra space.
