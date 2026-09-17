# LeetCode 980 — Unique Paths III

## Question

Given an `m × n` grid:

* `-1` → obstacle
* `0` → empty cell
* `1` → starting cell
* `2` → ending cell

Count paths from `1` to `2` such that **every non-obstacle cell is visited exactly once**.

---

## Example

```text
Input:
[
 [1,0,0,0],
 [0,0,0,0],
 [0,0,2,-1]
]

Output:
2
```

---

## Constraints

```text
1 <= m, n <= 20
1 <= m * n <= 20
grid[i][j] ∈ {-1, 0, 1, 2}
Exactly one 1 and one 2
```

---

## Topics

* DFS
* Recursion
* Backtracking
* Grid Traversal
* Visited Array

---

## Approach

1. Find the starting cell `1`.
2. Run DFS in 4 directions.
3. Mark the current cell as visited.
4. Don't visit obstacles or already visited cells.
5. When reaching `2`, check whether all non-obstacle cells are visited.
6. Count the path if valid.
7. Unmark the cell while backtracking.

### Core Pattern

```cpp
vis[r][c] = 1;     // Mark

DFS(next);         // Explore

vis[r][c] = 0;     // Backtrack
```

---

## Time Complexity

Let `K` = number of non-obstacle cells.

```text
O(4^K × m × n)
```

`m × n <= 20`, so this is feasible.

---

## Space Complexity

```text
O(m × n)
```

For the visited matrix + recursion stack.

---

## Key Idea

**DFS explores every possible path, and backtracking allows the same cell to be reused in different paths.**
