# 576. Out of Boundary Paths

## Question

Given an `m x n` grid, a ball starts at `(startRow, startColumn)`.

In one move, the ball can move **up, down, left, or right**.

Given `maxMove`, return the number of paths that move the ball **out of the grid** using at most `maxMove` moves.

Return the answer modulo `10^9 + 7`.

## Examples

### Example 1

**Input:**  
`m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0`

**Output:**  
`6`

### Example 2

**Input:**  
`m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1`

**Output:**  
`12`

### Example 3

**Input:**  
`m = 8, n = 7, maxMove = 16, startRow = 1, startColumn = 5`

**Output:**  
`102984580`

## Constraints

- `1 <= m, n <= 50`
- `0 <= maxMove <= 50`
- `0 <= startRow < m`
- `0 <= startColumn < n`
- Return answer modulo `10^9 + 7`

## Topics

- Dynamic Programming
- Grid DP
- Recursion → DP
- Space Optimization
- 2D DP

## Approach

Use DP based on the number of moves.

```text
dp[r][c]
= number of ways to leave the grid
  starting from (r, c)
  using the previous number of moves