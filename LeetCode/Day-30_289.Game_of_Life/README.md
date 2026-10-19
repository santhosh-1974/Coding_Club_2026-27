# 289. Game of Life

## Question

Given an `m x n` board of cells that are either live (`1`) or dead (`0`), compute the next state of the board using these rules:

1. A live cell with fewer than two live neighbors dies.
2. A live cell with two or three live neighbors stays alive.
3. A live cell with more than three live neighbors dies.
4. A dead cell with exactly three live neighbors becomes alive.

Each cell's eight neighbors are the cells horizontally, vertically, or diagonally adjacent to it. Update the board in-place.

## Examples

### Example 1

Input: `board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]`

Output: `[[0,0,0],[1,0,1],[0,1,1],[0,1,0]]`

### Example 2

Input: `board = [[1,1],[1,0]]`

Output: `[[1,1],[1,1]]`

## Constraints

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 25`
- `board[i][j]` is `0` or `1`.

## Topics

- Array
- Matrix
- Simulation

## Approach

1. Check all eight neighbors of every cell.
2. Encode changes temporarily in the board: `-1` means a live cell will die, and `2` means a dead cell will become alive. These markers let neighbor counts still recognize the original state.
3. After all cells have been processed, convert the temporary markers to their next-state values.

## Time Complexity

`O(m * n)` because each cell checks a fixed set of eight neighbors.

## Space Complexity

`O(1)` extra space, excluding the direction-offset arrays.
