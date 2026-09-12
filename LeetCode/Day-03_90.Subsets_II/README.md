# LeetCode 90 — Subsets II

## Problem

Given an integer array `nums` that may contain duplicates, return all possible subsets (the power set).

The solution set must **not contain duplicate subsets**.

You may return the subsets in any order.

### Example

```text
Input:
nums = [1,2,2]

Output:
[
  [],
  [1],
  [2],
  [1,2],
  [2,2],
  [1,2,2]
]
```

## Approach

Use **backtracking** to generate all possible subsets.

The main challenge is avoiding duplicate subsets when the array contains duplicate values.

### Steps

1. Sort the array so duplicate values become adjacent.
2. Start with an empty subset.
3. Add the current subset to the answer.
4. Try choosing each element from the current index.
5. Skip duplicate elements at the same recursion level.
6. Backtrack after exploring each choice.

### Why `i > index`?

Duplicates should be skipped only at the **same recursion level**.

For example:

```text
nums = [1,2,2]

        []
       /  \
     [2]  skip 2
      |
    [2,2]
```

The second `2` is allowed deeper in the recursion because `[2,2]` is a valid subset.

Therefore:

```text
Same recursion level   → Skip duplicate
Deeper recursion level → Allow duplicate
```

## Complexity

There can be up to `2^n` possible subsets.

```text
Time:  O(n × 2^n)

Space: O(n)              → Recursion + temporary subset
       O(n × 2^n)        → Output
```
