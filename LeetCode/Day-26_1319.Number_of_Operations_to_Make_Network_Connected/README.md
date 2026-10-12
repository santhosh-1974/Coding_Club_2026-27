# 1319. Number of Operations to Make Network Connected

## Question

There are `n` computers numbered from `0` to `n - 1` and a list of existing network cables. In one operation, you can remove a cable and connect two computers that are not directly connected. Return the minimum number of operations needed to connect all computers, or `-1` if it is impossible.

## Example

```text
Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
```

## Constraints

- `1 <= n <= 10^5`
- `n - 1 <= connections.length <= 10^5`
- `connections[i].length == 2`
- `0 <= connections[i][0], connections[i][1] < n`
- `connections[i][0] != connections[i][1]`
- No repeated connections.

## Topics

- Depth-First Search
- Breadth-First Search
- Union-Find
- Graph

## Approach

1. Use a disjoint-set data structure to track connected components.
2. For each connection, union its endpoints if they are in different components. Otherwise, count that cable as redundant.
3. If there are `components` separate groups, at least `components - 1` cables are needed to connect them.
4. Return `components - 1` when enough redundant cables exist; otherwise return `-1`.

## Time Complexity

`O((n + m) α(n))`, where `m` is the number of connections and `α` is the inverse Ackermann function.

## Space Complexity

`O(n)` for the disjoint-set structure.
