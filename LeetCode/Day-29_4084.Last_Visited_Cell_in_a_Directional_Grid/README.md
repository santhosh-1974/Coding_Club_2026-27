# 4084. Last Visited Cell in a Directional Grid

## Question

Given an `m x n` grid where each cell contains `'L'`, `'R'`, `'U'`, or `'D'`, start at `(0, 0)`, which is considered visited. At each step, follow the direction in the current cell. The process ends if the next move would leave the grid or enter a previously visited cell. Return the row and column of the last visited cell.

## Examples

### Example 1

Input: `grid = [["R","D"],["U","L"]]`

Output: `[1,0]`

Explanation: The path is `(0,0) -> (0,1) -> (1,1) -> (1,0)`. The next move would revisit `(0,0)`, so the last visited cell is `(1,0)`.

### Example 2

Input: `grid = [["R","R","R"]]`

Output: `[0,2]`

Explanation: The next move from `(0,2)` would leave the grid, so the last visited cell is `(0,2)`.

## Constraints

- `1 <= m == grid.length <= 10^5`
- `1 <= n == grid[i].length <= 10^5`
- `m * n <= 10^5`
- `grid[i][j]` is one of `'L'`, `'R'`, `'U'`, or `'D'`.

## Topics

- Array
- Hash Table
- Matrix
- Simulation

## Approach

1. Map each direction to its row and column offset.
2. Start from `(0,0)` and mark it visited.
3. Repeatedly follow the current cell's direction, moving only when the destination is in bounds and unvisited.
4. Stop when the next move is invalid and return the current cell.

## Time Complexity

`O(m * n)` in the worst case, since each cell is visited at most once.

## Space Complexity

`O(m * n)` for the visited grid, traversal stack, and the required input copy.
