# LeetCode 473 - Matchsticks to Square
## Problem
Given an array `matchsticks` where `matchsticks[i]` is the length of the i-th matchstick, return `true` if all matchsticks can be used exactly once (without breaking any) to form a square with four equal sides.

## Example
Input:
matchsticks = [1,1,2,2,2]
Output:
true
Explanation: Side length 2 — two sticks of length 1 form one side, the 2's form the others.

Input:
matchsticks = [3,3,3,3,4]
Output:
false

## Approach
Backtracking — partition the sticks into 4 groups of equal sum:

1. **Feasibility checks:** the total sum must be divisible by 4 (`target = sum / 4`), and no stick may be longer than `target`.
2. **Sort descending:** placing the longest sticks first fills sides quickly and triggers the `sum > target` prune much earlier, massively cutting the search space.
3. **Recursive fill (`helper`):** try to complete the current side up to `target` by picking unused sticks in order:
   - When the running `sum` reaches `target`, one side is done — recurse to build the next side (`k-1`) starting from index 0 with sum 0.
   - When only one side remains (`k == 1`), the leftover sticks automatically form the last side → `true`.
   - Skip used sticks and any stick that would overflow `target`; backtrack by unmarking on failure.

Fixing sides one at a time (rather than assigning sticks freely) plus the index-start ordering removes most symmetric duplicate states.

## Complexity
Time Complexity: O(4^n) worst case — each stick can go to one of 4 sides — but heavy pruning (sorting, overflow cutoffs) makes n ≤ 15 practical.
Space Complexity: O(n) — the `used` array and recursion depth.

## Topics
- Array
- Backtracking
- Bit Manipulation
- Dynamic Programming

## LeetCode
Problem 473 - Matchsticks to Square
