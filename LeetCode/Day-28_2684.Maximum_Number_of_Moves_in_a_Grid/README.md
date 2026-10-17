# 2684. Maximum Number of Moves in a Grid

## Question

Given an `m x n` grid, you can start at any cell in the first column. From a cell `(row, col)`, you may move to one of the following cells in the next column:

- `(row - 1, col + 1)`
- `(row, col + 1)`
- `(row + 1, col + 1)`

A move is valid only if the destination cell contains a strictly greater value than the current cell. Return the maximum number of moves that can be made.

## Examples

### Example 1

Input: `grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]`

Output: `3`

Explanation: One path with three moves is `3 -> 4 -> 9 -> 11`.

### Example 2

Input: `grid = [[3,2,4],[2,1,9],[1,1,7]]`

Output: `0`

Explanation: No valid move can be made from the first column.

## Constraints

- `m == grid.length`
- `n == grid[i].length`
- `2 <= m, n <= 1000`
- `1 <= grid[i][j] <= 10^6`

## Topics

- Array
- Dynamic Programming
- Matrix

## Approach

1. Create a DP table where `dp[row][col]` stores the maximum moves possible starting from that cell.
2. Process columns from right to left. For each cell, check the three possible cells in the next column.
3. If a destination is in bounds and has a strictly greater value, update the current cell with `dp[destination] + 1`.
4. The answer is the maximum DP value among cells in the first column.

## Time Complexity

`O(m * n)`, checking at most three destinations for each cell.

## Space Complexity

`O(m * n)` for the DP table.
