# 79. Word Search

## Question

Given an `m x n` grid of characters and a string `word`, return `true` if the word can be found in the grid. Consecutive letters must be in horizontally or vertically adjacent cells, and each cell can be used only once in a word.

## Example

```text
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

## Constraints

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` and `word` contain only English letters.

## Topics

- Array
- String
- Backtracking
- Depth-First Search
- Matrix

## Approach

1. Try each cell matching the first character as a starting point.
2. Use depth-first search to check the four neighboring cells for the next character.
3. Mark each cell as visited while exploring so it cannot be reused in the current path.
4. Backtrack by unmarking a cell when that path does not find the word.

## Time Complexity

`O(m * n * 4^L)` in the worst case, where `L` is the word length.

## Space Complexity

`O(m * n + L)` for the visited grid and recursion stack.
