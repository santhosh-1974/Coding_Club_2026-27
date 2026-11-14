# LeetCode 1222 - Queens That Can Attack the King
## Problem
On a 0-indexed 8 x 8 chessboard there are multiple black queens and one white king. Given the `queens` positions and the `king` position, return the coordinates of all queens that can **directly** attack the king (same row, column, or diagonal with no other queen between them). Answer may be in any order.

## Example
Input:
queens = [[0,1],[1,0],[4,0],[0,4],[3,3],[2,4]], king = [0,0]
Output:
[[0,1],[1,0],[3,3]]

Input:
queens = [[0,0],[1,1],[2,2],[3,4],[3,5],[4,4],[4,5]], king = [3,3]
Output:
[[2,2],[3,4],[4,4]]

## Approach
A queen attacks the king only along one of **8 rays** (up/down/left/right and the 4 diagonals), and only the *closest* queen on each ray counts. Reduce the problem to at most one winner per direction:

1. Sort the queens by Manhattan distance to the king — nearer queens are considered first, so the closest one on a ray claims it before any blocked queen behind it can.
2. Classify each queen by which of the 8 rays it lies on:
   - Same column (`x == king.x`): directions 0 (below) and 1 (above).
   - Same row (`y == king.y`): directions 2 (left) and 3 (right).
   - Anti-diagonal (`x + y == king.x + king.y`): directions 4 and 5.
   - Main diagonal (`y - x == king.y - king.x`): directions 6 and 7.
3. For each queen, first confirm it is actually on the king's side of the ray (e.g., `y < king.y` for the "below" case), then check a `vis[8]` flag array — if that direction hasn't been claimed yet, take the queen and mark the direction.

Because sorting guarantees proximity order, marking each direction once ensures only the nearest attacking queen per ray is reported.

## Complexity
Time Complexity: O(q log q) for the sort plus O(q) classification — q = number of queens (≤ 63), so effectively constant.
Space Complexity: O(1) extra — a fixed 8-slot flag array (plus output).

## Topics
- Array
- Matrix
- Simulation

## LeetCode
Problem 1222 - Queens That Can Attack the King
