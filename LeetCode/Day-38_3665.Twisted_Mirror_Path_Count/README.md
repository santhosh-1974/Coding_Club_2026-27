# 3665. Twisted Mirror Path Count

## Question

You are given an `m x n` grid where each cell is either empty (`0`) or contains a mirror (`1`). A robot starts at the top-left corner `(0, 0)` and wants to reach the bottom-right corner `(m-1, n-1)`. The robot can only move right or down. When it enters a mirror cell coming from the left, it is forced to move down; when it enters coming from above, it is forced to move right. Return the number of distinct paths that reach the bottom-right corner, modulo `10^9 + 7`.

## Example

```text
Input: grid = [[0,1,0],[0,0,0],[0,1,0]]
Output: 4
```

## Constraints

- `1 <= m, n <= 10^5` (product bounded by grid size limit)
- `grid[i][j]` is `0` or `1`
- `grid[0][0]` and `grid[m-1][n-1]` are `0`

## Topics

- Dynamic Programming
- Matrix

## Approach

1. Track `dp[c][fromLeft]` = number of ways to reach the current row's cell in column `c`, arriving either from the left (`fromLeft = 1`) or from above (`fromLeft = 0`), since the mirror's redirect depends on the entry direction.
2. Process rows from bottom to top and columns from right to left (right-to-left so `temp[c+1][1]`, the "arrived from the left" value in the same row, is already computed).
3. On an empty cell: ways = (from above in this column) + (from the left in this row) = `dp[c][0] + temp[c+1][1]`.
4. On a mirror cell: arriving from the left forces down → take `dp[c][0]` (ways at the cell below arriving from above); arriving from above forces right → take `temp[c+1][1]`.
5. The bottom-right corner counts as exactly one way. The answer is `dp[0][0]`.

## Time Complexity

`O(m * n)` — each cell is processed once with constant work per state.

## Space Complexity

`O(n)` — two rows of DP states (previous row and current row).
