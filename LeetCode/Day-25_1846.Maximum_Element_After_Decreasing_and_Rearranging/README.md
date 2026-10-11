# 1846. Maximum Element After Decreasing and Rearranging

## Question

Given an array `arr`, rearrange its elements and decrease some values so that the first element is `1` and the difference between every pair of adjacent elements is at most `1`. Return the largest possible value of the final element.

## Example

```text
Input: arr = [2, 2, 1, 2, 1]
Output: 2
```

## Constraints

- `1 <= arr.length <= 10^5`
- `1 <= arr[i] <= 10^5`

## Topics

- Array
- Greedy
- Sorting

## Approach

1. Sort the array in ascending order.
2. Set the first value to `1`.
3. Walk through the sorted values. When a value differs from the previous adjusted value, set it to at most one greater than that previous value.
4. Return the last adjusted value.

## Time Complexity

`O(n log n)` for sorting the array.

## Space Complexity

`O(1)` extra space, excluding the space used internally by sorting.
