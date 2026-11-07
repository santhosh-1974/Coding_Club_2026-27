# LeetCode 1780 - Check if Number is a Sum of Powers of Three
## Problem
Given an integer `n`, return `true` if it is possible to represent `n` as the sum of **distinct** powers of three. Otherwise, return `false`.

An integer `y` is a power of three if there exists an integer `x` such that `y == 3^x`.

## Example
Input:
n = 12
Output:
true
Explanation:
12 = 3^1 + 3^2 = 3 + 9.

Input:
n = 91
Output:
true
Explanation:
91 = 3^0 + 3^2 + 3^4 = 1 + 9 + 81.

Input:
n = 21
Output:
false
Explanation:
21 cannot be written as a sum of distinct powers of three.

## Approach
Use recursion (include / exclude pattern). At each index `i`, we consider the power `3^i`:

1. If `n` becomes `0`, a valid combination of distinct powers has been found → return `true`.
2. If `n < 3^i`, no remaining power can fit → return `false`.
3. Otherwise try both choices:
   - **Take** the power: recurse with `n - 3^i` and `i + 1`.
   - **Skip** the power: recurse with `n` and `i + 1`.
4. Return true if either branch succeeds.

Since each power can be used at most once, distinctness is guaranteed.

## Complexity
Time Complexity: O(log n) powers exist up to n, so 2^(log n) branches in the worst case; practically very small.
Space Complexity: O(log n) — recursion stack depth.

## Topics
- Math
- Recursion
- Backtracking

## LeetCode
Problem 1780 - Check if Number is a Sum of Powers of Three
