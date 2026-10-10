# 3075. Maximize Happiness of Selected Children

## Question

Given an integer array `happiness` and an integer `k`, choose `k` children in sequence. Each time a child is chosen, the happiness of every child not yet chosen decreases by 1, but cannot go below 0. Return the maximum total happiness of the chosen children.

## Example

```text
Input: happiness = [1, 2, 3], k = 2
Output: 4
```

## Constraints

- `1 <= happiness.length <= 2 * 10^5`
- `1 <= happiness[i] <= 10^8`
- `1 <= k <= happiness.length`

## Topics

- Array
- Greedy
- Sorting

## Approach

1. Sort the happiness values in descending order so the largest values are selected first.
2. For the child selected at position `c`, add `max(happiness[c] - c, 0)` to the total.
3. Stop after selecting `k` children.

## Time Complexity

`O(n log n)` for sorting the array.

## Space Complexity

`O(1)` extra space, excluding the space used internally by sorting.
